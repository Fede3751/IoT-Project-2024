import math

import rclpy
from rclpy.node import Node

from rclpy.executors import MultiThreadedExecutor


from std_msgs.msg import String
from geometry_msgs.msg import Point
from nav_msgs.msg import Odometry


NUMBER_OF_SENORS = 3
NUMBER_OF_BALLOONS = 3
SENSORS_RANGE = 10

class SimulationManager(Node):

    def __init__(self):

        super().__init__('simulation_manager')


        self.sensor_positions = {}
        self.balloon_positions = {}


        for i in range(NUMBER_OF_SENORS):

            self.create_subscription(
                Odometry,
                f'Sensor_{i}/odometry',
                lambda odometry_msg, sensor_id = i: self.store_sensor_position(sensor_id, odometry_msg),
                10
                #self.store_sensor_position
            )

            self.create_subscription(
                String,
                f'Sensor_{i}/tx_data',
                lambda string_msg, sensor_id = i: self.forward_data(sensor_id, string_msg),
                #self.forward_data,
                10
            )

        self.balloons_rx = {}

        for i in range(NUMBER_OF_BALLOONS):


            self.create_subscription(
                Odometry,
                f'Balloon_{i}/odometry',
                lambda odometry_msg, balloon_id = i: self.store_balloon_position(balloon_id, odometry_msg),
                10
                #self.store_sensor_position
            )

            self.balloons_rx[i] = self.create_publisher(
                String,
                f'Balloon_{i}/rx_data',
                10
            )

    def store_sensor_position(self, sensor_id, position : Odometry):

        #self.get_logger().info(f"Sensor {sensor_id} is giving us position: {position.pose.pose.position}")
        self.sensor_positions[sensor_id] = position.pose.pose.position

    def store_balloon_position(self, balloon_id, position : Odometry):

        #self.get_logger().info(f"Balloon {balloon_id} is giving us position: {position.pose.pose.position}")
        self.balloon_positions[balloon_id] = position.pose.pose.position


    def forward_data(self, sensor_id, msg : String):

        # self.get_logger().info("Forwarding data")

        # self.get_logger().info(f"{self.sensor_positions}")
        # self.get_logger().info(f"{self.balloon_positions}")


        for i in range(NUMBER_OF_BALLOONS):

            if sensor_id in self.sensor_positions and i in self.balloon_positions:
                print(point_distance(self.sensor_positions[sensor_id], self.balloon_positions[i]))
                if point_distance(self.sensor_positions[sensor_id], self.balloon_positions[i]) < SENSORS_RANGE:
                    self.balloons_rx[i].publish(msg)
        




def point_distance(p0 : Point, p1 : Point):

    p0 = (p0.x, p0.y, p0.z)
    p1 = (p1.x, p1.y, p1.z)

    vec = (p1[0] - p0[0], p1[1] - p0[1], p1[2] - p0[2])
    return math.sqrt(vec[0]**2 + vec[1]**2 + vec[2]**2)




def main():

    rclpy.init()

    simulationManager= SimulationManager()
    executor = MultiThreadedExecutor()
    executor.add_node(simulationManager)

    executor.spin()

    executor.shutdown()
    simulationManager.destroy_node()

    rclpy.shutdown()
    
