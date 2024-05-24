# IoT-Project-2024

<p align="center">
  <img src="https://fede3751.github.io/IoT-lectures-2024/imgs/project/project_splashart_2024.png">
</p>

Official repository for the IoT project 2024.


You can start the simulation displayed in the image with the command:

```
ros2 launch project_main simulation_launch.py
```


The project containts two ROS Packages, you can start from them to build your solution:

**project_interfaces**<br>
  &emsp; Used to store the interfaces used for the project. Currently contains only the **Patrol** action.<br>
**project_main**<br>
  &emsp; Main package where all the code is stored. Your solution can start by building on top of this package, or in a new package alongside this.<br>
  &emsp; Having a side-package is suggested in order to prevent conflicts when new updates are pushed.

The file configuration to launch the simulation is **simulation_launch.py** inside the **launch** folder of **project_main**.
To help with the implementation of timed events, the **sim_utils.py** file contains an **EventScheduler** class which allows to schedule events based on simulation time.<br><br>

For the full assignment of the project, please refer to the main file here: <a href="https://fede3751.github.io/IoT-lectures-2024/misc_files/IoT_Project_2024_Assignment.pdf">IoT_Project_2024_Assignment.pdf</a><br><br>

Good luck!
