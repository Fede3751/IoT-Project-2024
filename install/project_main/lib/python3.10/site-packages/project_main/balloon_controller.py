import time
import math

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle
from rclpy.executors import MultiThreadedExecutor

from std_msgs.msg import String
from geometry_msgs.msg import Point, Vector3, Twist
from nav_msgs.msg import Odometry

from project_interfaces.action import Patrol


MIN_ALTITUDE_TO_PERFORM_PATROL = 1


class BalloonController(Node):

    def __init__(self):
        super().__init__("drone_controller")


        self.position = Point()
        self.yaw = 0

        self.stop_msg = Twist()

        self.cmd_vel_publisher = self.create_publisher(
            Twist,
            'cmd_vel',
            10
        )

        self.odometry_subscrber = self.create_subscription(
            Odometry,
            'odometry',
            self.store_position,
            10
        )


        self.rx_data = self.create_subscription(
            String,
            'rx_data',
            self.rx_callback,
            10
        )

        self.patrol_action_server = ActionServer(
            self,
            Patrol,
            'patrol',
            self.execute_patrol_action
        )


    def rx_callback(self, msg : String):
        
        

        self.get_logger().info(msg.data)



    def store_position(self, odometry_msg : Odometry):

        self.position = odometry_msg.pose.pose.position
        self.yaw = get_yaw(
            odometry_msg.pose.pose.orientation.x,
            odometry_msg.pose.pose.orientation.y,
            odometry_msg.pose.pose.orientation.z,
            odometry_msg.pose.pose.orientation.w
        )
        #self.get_logger().info(f"Storing position {self.drone_position}")

    def execute_patrol_action(self, goal : ServerGoalHandle):


        command_goal : Patrol.Goal = goal.request

        self.get_logger().info("Action requested. Performing movement to target:")
        self.get_logger().info(str(command_goal.targets))

        self.fly_to_altitude(MIN_ALTITUDE_TO_PERFORM_PATROL)
        
        for target in command_goal.targets:
                
            self.get_logger().info("Altitude reached, now rotating...")
            self.rotate_to_target(target)

            self.get_logger().info("Rotated to target. Now moving towards it...")
            
            # Next set of exercises will pick up from here!
            self.move_to_target(target)

            self.get_logger().info("Movement completed, setting goal succeeded and completing action!")
        
        
        goal.succeed()

        result =  Patrol.Result()
        result.result = "Movement completed"

        return result

    def fly_to_altitude(self, altitude):

        # Instantiate the move_up message
        move_up = Twist()
        move_up.linear = Vector3(x=0.0, y=0.0, z=1.0)
        move_up.angular = Vector3(x=0.0, y=0.0, z=0.0)

        self.cmd_vel_publisher.publish(move_up)

        # Wait for the drone to reach the desired altitude
        while(self.position.z < altitude):
            time.sleep(0.1)

        # Stop movement after the altitude has been reached
        stop_mov = Twist()
        stop_mov.linear = Vector3(x=0.0, y=0.0, z=0.0)
        stop_mov.angular = Vector3(x=0.0, y=0.0, z=0.0)
        self.cmd_vel_publisher.publish(stop_mov)

    def rotate_to_target(self, target, eps = 0.2):

        target = (target.x, target.y, target.z)

        # We compute the angle between the current target position and the target
        # position here

        start_position = (self.position.x, self.position.y)
        target_angle = angle_between_points(start_position, target)
        angle_to_rotate = target_angle - self.yaw

        # Normalize the angle difference to be within the range [-pi, pi]
        angle_to_rotate = (angle_to_rotate + math.pi) % (2 * math.pi) - math.pi

        # And then assign the direction of the rotation correctly
        rotation_dir = 1 if angle_to_rotate < 0 else -1
        
        # Prepare the cmd_vel message
        move_msg = Twist()
        move_msg.linear = Vector3(x=0.0, y=0.0, z=0.0)
        move_msg.angular = Vector3(x=0.0, y=0.0, z = 0.5 * rotation_dir)
        self.cmd_vel_publisher.publish(move_msg)

        # Publish the message until the correct rotation is reached (accounting for some eps error)
        # Note that here the eps also helps us stop the drone and not overshoot the target, as
        # the drone will keep moving for a while after it receives a stop message
        # Also note that rotating the drone too fast will make it loose altitude.
        # You can account for that by also giving some z linear speed to the rotation movement.
        while abs(angle_to_rotate) > eps:
            angle_to_rotate = target_angle - self.yaw

            # self.get_logger().info(f"Rotation: {self.yaw}")
            # No sleep here. We don't want to miss the angle by sleeping too much. Even 0.1 seconds
            # could make us miss the given epsilon interval

        # When done, send a stop message to be sure that the drone doesn't
        # overshoot its target
        stop_msg = Twist()
        stop_msg.linear = Vector3(x=0.0, y=0.0, z=0.0)
        stop_msg.angular = Vector3(x=0.0, y=0.0, z=0.0)
        self.cmd_vel_publisher.publish(stop_msg)

    def move_to_target(self, target, eps = 0.5, angle_eps = 0.05):


        target = (target.x, target.y, target.z)
        position = (self.position.x, self.position.y, self.position.z)
        distance = point_distance(position, target)

        while (distance > eps):

            mv = move_vector(position, target)

            twist_msg = Twist()
            twist_msg.linear.x = mv[0]
            twist_msg.linear.z = mv[1]


            position = (self.position.x, self.position.y, self.position.z)
            distance = point_distance(position, target)

            target_angle = angle_between_points(position, target)


            angle = angle_between_points(position, target)

            if not (angle-angle_eps < self.yaw < angle+angle_eps):
                angle_diff = (self.yaw-angle)
                twist_msg.angular = Vector3(x=0.0, y=0.0, z=math.sin(angle_diff))


            self.cmd_vel_publisher.publish(twist_msg)


        self.cmd_vel_publisher.publish(self.stop_msg)


def angle_between_points(p0 : tuple, p1 : tuple):

    '''
    Computes the angle between the two given points, in radiants.
    p0: the coordinates of the first point (x0, y0)
    p1: the coordinates of the second point (x1, y1)
    '''

    vector_between = (p1[0] - p0[0], p1[1] - p0[1])

    norm = math.sqrt(vector_between[0] ** 2 + vector_between[1] ** 2)
    direction = (vector_between[0] / norm, vector_between[1] / norm)

    return math.atan2(direction[0], direction[1]) % (math.pi * 2)

def point_distance(p0, p1):

    vec = (p1[0] - p0[0], p1[1] - p0[1], p1[2] - p0[2])
    return math.sqrt(vec[0]**2 + vec[1]**2 + vec[2]**2)


def move_vector(p0, p1):

    vec = (math.sqrt((p1[0] - p0[0])**2 + (p1[1] - p0[1])**2), p1[2] - p0[2])
    norm = math.sqrt(vec[0]**2 + vec[1]**2)

    return (vec[0]/norm, vec[1]/norm)

def euler_from_quaternion(x, y, z, w):
    
    """
    Convert a quaternion into euler angles (roll, pitch, yaw)
    roll is rotation around x in radians (counterclockwise)
    pitch is rotation around y in radians (counterclockwise)
    yaw is rotation around z in radians (counterclockwise)
    """

    t0 = +2.0 * (w * x + y * z)
    t1 = +1.0 - 2.0 * (x * x + y * y)
    roll_x = math.atan2(t0, t1)

    t2 = +2.0 * (w * y - z * x)
    t2 = +1.0 if t2 > +1.0 else t2
    t2 = -1.0 if t2 < -1.0 else t2
    pitch_y = math.asin(t2)

    t3 = +1.0 - 2.0 * (y * y + z * z)
    t4 = +2.0 * (w * z + x * y)
    yaw_z = math.atan2(t3, t4)

    return roll_x, pitch_y, yaw_z # in radians

def get_yaw(x, y, z, w):
    return euler_from_quaternion(x,y,z,w)[2] % (math.pi * 2)


def main():
    
    rclpy.init()
    executor = MultiThreadedExecutor()

    drone_controller = BalloonController()
    executor.add_node(drone_controller)

    executor.spin()

    drone_controller.destroy_node()
    executor.shutdown()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
