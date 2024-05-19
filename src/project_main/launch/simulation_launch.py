import sys

from launch import LaunchDescription
from launch_ros.actions import Node

from launch_ros.substitutions import FindPackageShare
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution

from project_main.sim_utils import spawn_sdf




WORLD_NAME = "iot_project_world"

#-----------------------------------------------------------------------------------------------
# Launch file for the IoT Project. Launches all the nodes required to start the final solution
#-----------------------------------------------------------------------------------------------

def generate_launch_description():


    # SIMULATION_ARGUMENT = sys.argv[4]

    # simulation_config =  sim_utils.import_simulation_config(SIMULATION_ARGUMENT)
    
    # if not simulation_config:
    #     return LaunchDescription([])
    
    # wind_velocity_string = f"{simulation_config.wind_vector[0]} {simulation_config.wind_vector[1]} {simulation_config.wind_vector[2]}"
    # sim_utils.edit_sdf_and_save(simulation_config.world_file, f"{simulation_config.world_file}_instance", ['linear_velocity'], [wind_velocity_string])


    #------------------- Launch Gazebo here, with the iot_project_world world --------------------
    targets_to_spawn = [
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('ros_gz_sim'),
                'launch/'
                'gz_sim.launch.py',
            ])
            ]),
            launch_arguments={
            'gz_args' : f"resources/{WORLD_NAME}.sdf"
            }.items()
        )
    ]

    #------------------------------ Bridge for the simulation clock ------------------------------
    targets_to_spawn.append(
        Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        arguments=[
            f"/world/{WORLD_NAME}/clock@rosgraph_msgs/msg/Clock@ignition.msgs.Clock"
        ]
        )
    )


    #-------------------------- Spawn 3 balloons and bridge their topics -------------------------
    for i in range(3):
        targets_to_spawn.append(spawn_sdf("resources/balloon/balloon.sdf", id = i, pos = (0, i*5, 0)))

        # Spawn bridge for cmd_vel and odometry for each of the spawned object
        targets_to_spawn.append(
        Node(
            package="ros_gz_bridge",
            executable="parameter_bridge",
            arguments=[
            f"/Balloon_{i}/cmd_vel@geometry_msgs/msg/Twist@ignition.msgs.Twist"
            ]
        )
        )
        targets_to_spawn.append(
        Node(
            package="ros_gz_bridge",
            executable="parameter_bridge",
            arguments=[
            f"/Balloon_{i}/odometry@nav_msgs/msg/Odometry@ignition.msgs.Odometry"
            ]
        )
        )


    #-------------------------- Spawn 3 sensors and bridge their topics -------------------------
    for i in range(3):
        targets_to_spawn.append(spawn_sdf("resources/sensor/sensor.sdf", id = i, pos = (10, i*5, 0)))

        targets_to_spawn.append(
        Node(
            package="ros_gz_bridge",
            executable="parameter_bridge",
            arguments=[
            f"/Sensor_{i}/odometry@nav_msgs/msg/Odometry@ignition.msgs.Odometry"
            ]
        )
        )



    #------------------------------------ Spawn base station -------------------------------------
    targets_to_spawn.append(spawn_sdf("resources/base_station/base_station.sdf", pos = (-5, -5, 0)))
    targets_to_spawn.append(
        Node(
            package="ros_gz_bridge",
            executable="parameter_bridge",
            arguments=[
            f"/base_station/odometry@nav_msgs/msg/Odometry@ignition.msgs.Odometry"
            ]
        )
    )


    




    # #-------- Spawns drones and bridges all the cmd_vel and odometry topics of the drones --------
    # for target_count in range(simulation_config.no_drones):

    #     drone_position_y = (-(simulation_config.no_drones/2) + target_count + 0.5) * 2

    #     targets_to_spawn.append(
    #         sim_utils.spawn_drone(target_count, (0, drone_position_y, 0))
    #     )




    # #---------------------------- Spawns targets inside the simulation ---------------------------

    # targets_argument = []
    # target_count = 0

    # for target_count in range(simulation_config.no_targets):

    #     target_position = simulation_config.target_positions[target_count]

    #     targets_to_spawn.append(
    #         Node(
    #             package='ros_gz_sim',
    #             executable='create',
    #             arguments= [
    #                 '-world',
    #                 WORLD_NAME,
    #                 '-file',
    #                 './gazebo_resources/target_obj_blue.sdf',
    #                 "-name",
    #                 "Target "+str(target_count+1),
    #                 "-x",
    #                 str(target_position[0]),
    #                 "-y",
    #                 str(target_position[1]),
    #                 "-z",
    #                 str(target_position[2])
    #             ]
    #         )
    #     )


    #     # target_position = simulation_config.target_positions[target_count]
    #     # target_threshold = simulation_config.threshold_values[target_count]

    #     # targets_argument.append("Target %d" % (target_count + 1))
    #     # targets_argument.append(target_position[0])
    #     # targets_argument.append(target_position[1])
    #     # targets_argument.append(target_position[2])
    #     # targets_argument.append(target_threshold)



    # #-------------------------------- Tester and grader are started here -------------------------
    # targets_to_spawn.append(
    #     Node(
    #     package='iot_project_manager',
    #     executable='target_handler',
    #     arguments=[SIMULATION_ARGUMENT],
    #     output='screen',
    #     emulate_tty=True,
    #     name='iot_manager'
    #     )
    # )

    # targets_to_spawn.append(
    #     Node(
    #     package='iot_project_grader',
    #     executable='display',
    #     output='screen',
    #     emulate_tty=True,
    #     name='iot_grader'
    #     )
    # )

    # targets_to_spawn.append(
    #     Node(
    #     package='iot_project_animator',
    #     executable='color_changer',
    #     output='screen',
    #     emulate_tty=True,
    #     name='iot_animator'
    #     )
    # )


    # #------------------------- Finally, launch the solution launch file --------------------------


    # targets_to_spawn.append(
    #     IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource([
    #         PathJoinSubstitution([
    #             FindPackageShare('iot_project_solution_src'),
    #             'launch.py',
    #         ])
    #     ]), launch_arguments = {
    #         'no_drones' : str(simulation_config.no_drones)
    #     }.items()
    #     )
    # )

    # #---------------------------------------------------------------------------------------------


    return LaunchDescription(targets_to_spawn)
