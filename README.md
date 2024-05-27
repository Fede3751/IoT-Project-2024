# IoT-Project-2024

<p align="center">
  <img src="https://fede3751.github.io/IoT-lectures-2024/imgs/project/project_splashart_2024.png">
</p>

Official repository for the IoT project 2024.

## Launching the Simulation

You can start the simulation displayed in the image with the command:

```
ros2 launch project_main simulation_launch.py
```

Please note that in order for resources to be correctly found by gazebo, you should not launch your simulation outside this workspace.<br><br>

## Packages Organization

The project containts two ROS Packages, you can start from them to build your solution:

**project_interfaces**<br>
  &emsp; Used to store the interfaces used for the project. Currently contains only the **Patrol** action.<br><br>
**project_main**<br>
  &emsp; Main package where all the code is stored. Your solution can start by building on top of this package, or in a new package alongside this.
  Having a side-package is suggested in order to prevent conflicts when new updates are pushed.


The file configuration to launch the simulation is **simulation_launch.py** inside the **launch** folder of **project_main**.<br><br>


## ROS Nodes

There are currently multiple nodes being launched:

**SimulationManager**:<br>
&emsp; Handles the main logic of the simulation. The behaviour of the range of the sensors and the tranmission between the various interfaces of the devices in the simulation is described here.
You currently have already implemented for you the bridge between the interfaces of the sensors and those of the balloons.<br><br>
**BalloonController**:<br>
&emsp; Used to describe the behaviour the balloons. The **Patrol** action server is advertised here, along with the subscription to movement and tranmission topics. There is currently no implementation to handle incoming packets from sensors, just a simple print message.<br><br>
**SensorController**:<br>
&emsp; Same as the controller for the balloons. The sensors currently output a simple string every second.<br><br>
**FleetCoordinator**:<br>
&emsp; Class which acts as an ActionClient to the balloons and coordinate their moving according to the demands.<br><br><br>

To help with the implementation of timed events, the **sim_utils.py** file contains an **EventScheduler** class which allows to schedule events based on simulation time.<br><br>

## Project Assignment

For the full assignment of the project, please refer to the main file here: <a href="https://fede3751.github.io/IoT-lectures-2024/misc_files/IoT_Project_2024_Assignment.pdf">IoT_Project_2024_Assignment.pdf</a><br><br>

Good luck!
