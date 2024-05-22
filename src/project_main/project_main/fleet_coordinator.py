import sys
from time import sleep
from threading import Thread
from enum import Enum

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.executors import MultiThreadedExecutor

from geometry_msgs.msg import Point
from nav_msgs.msg import Odometry
from project_interfaces.action import Patrol


NUMBER_OF_BALLOONS = int(sys.argv[1])
NUMBER_OF_SENSORS = int(sys.argv[2])

HOVERING_HEIGHT = 15.0


class FleetCoordinator(Node):

    """
    Fleet Coordinator class, used the manage the whole fleet of Balloons and Drones.
    This is where most of the task should be submitted by default.
    """
    
    def __init__(self):

        super().__init__('fleet_coordinator')

        self.balloon_action_clients = {}
        self.sensor_positions = {}      
        self.balloon_states = {} 

        for i in range(NUMBER_OF_BALLOONS):

            self.balloon_action_clients[i] = ActionClient(
                    self,
                    Patrol,
                    f'/Balloon_{i}/patrol'
                )
            
            self.balloon_states[i] = BalloonState.LANDED
            


        for i in range(NUMBER_OF_SENSORS):
            self.create_subscription(
                Odometry,
                f'Sensor_{i}/odometry',
                lambda msg, id = i : self.store_sensor_position(id, msg),
                10
            )




    def patrol_targets(self):

        """
        Method used to keep the fleet of Balloons constantly patrolling the set of targets.
        When a patrolling task has been completed, a new one with the same targets is given again.
        """

        def patrol_targets_inner():

            while True:
                for i in range(NUMBER_OF_BALLOONS):
                    # Do not resubmit tasks to already moving balloons
                    if not self.balloon_states[i] is BalloonState.MOVING:
                        self.submit_task(i)
            
        # Start this function in another thread, so that the node can start spinning immediately after
        # this function has finished
        Thread(target=patrol_targets_inner).start()


    def submit_task(self, uav_id : int):

        # Wait for the action server to go online
        while not self.balloon_action_clients[uav_id].wait_for_server(1) or len(self.sensor_positions) < NUMBER_OF_SENSORS:
            self.get_logger().info("Waiting for action server to come online and sensors to announce their position")
            sleep(3)

        # Set the Balloon to moving state
        self.balloon_states[uav_id] = BalloonState.MOVING
        goal = Patrol.Goal()
        goal.targets = []

        # Just iterate through all the sensors in a round-robin fashion
        for target in range(len(self.sensor_positions)):

            # Start from the sensor with the id equal to the balloon id
            actual_target = (target + uav_id) % len(self.sensor_positions)
            goal.targets.append(self.sensor_positions[actual_target])

            # Set the height to a predefined value, as the sensors will be on the ground, we want to hover them
            goal.targets[-1].z = HOVERING_HEIGHT + (uav_id * 8.0)



        self.get_logger().info(f"Submitting task for Balloon {uav_id}")

        # Submit the task here and add a callback for when the submission is accepted
        patrol_future = self.balloon_action_clients[uav_id].send_goal_async(goal)
        patrol_future.add_done_callback(lambda future, uav_id = uav_id : self.patrol_submitted_callback(uav_id, future))


    def patrol_submitted_callback(self, uav_id, future):

        # Check if the patrol action was accepted
        goal_handle = future.result()
    
        if not goal_handle.accepted:
            # If not, set the balloon back to hovering, and return
            self.get_logger().info("Task has been refused by the action server")
            self.balloon_states[uav_id] = BalloonState.HOVERING
            return
        
        result_future = goal_handle.get_result_async()

        # Add a callback for when the action is completed
        result_future.add_done_callback(lambda future, uav_id = uav_id : self.patrol_completed_callback(uav_id, future))


    def patrol_completed_callback(self, uav_id, future):

        # Action completed, Balloon can go back to hovering. Note that we don't check if the patrol was correctly completed,
        # you may have to handle such cases
        self.get_logger().info(f"Patrolling action for Balloon {uav_id} has been completed. Drone is going idle")
        self.balloon_states[uav_id] = BalloonState.HOVERING


    def store_sensor_position(self, id, msg : Odometry):
        self.sensor_positions[id] = msg.pose.pose.position



class BalloonState(Enum):
    LANDED = 1
    HOVERING = 2
    MOVING = 3


def main():

    rclpy.init()

    executor = MultiThreadedExecutor()
    fleet_coordinator = FleetCoordinator()

    executor.add_node(fleet_coordinator)
    fleet_coordinator.patrol_targets()

    executor.spin()

    executor.shutdown()
    fleet_coordinator.destroy_node()
    rclpy.shutdown()

    