import rclpy
from rclpy.node import Node

from rclpy.executors import MultiThreadedExecutor


from std_msgs.msg import String

class SensorController(Node):

    def __init__(self):
        super().__init__('sensor_controller')

        self.tx_topic = self.create_publisher(
            String,
            'tx_data',
            10
        )

        self.create_timer(1, self.simple_publish)


    def simple_publish(self):

        #self.get_logger().info("Publishing sensor data")

        msg = String()
        msg.data = "HELLO FROM A SENSOR!"

        self.tx_topic.publish(msg)


def main():
    
    rclpy.init()
    executor = MultiThreadedExecutor()

    sensor_controller = SensorController()
    executor.add_node(sensor_controller)

    executor.spin()

    sensor_controller.destroy_node()
    executor.shutdown()
    rclpy.shutdown()
