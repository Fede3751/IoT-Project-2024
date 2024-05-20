import os
import re

from launch_ros.actions import Node

WORLD_NAME = "iot_project_world"


# Function used to dynamically spawn a new sdf object at the start of the simulation. Use this to spawn multiple times
# the same object with different ids in your launch file.
# This function additionally modifies all the occurrences of the model name inside the SDF, keeping plugins such as
# OdometryPublisher consistent even without namespaces set. All occurrences of [MODEL_NAME] inside the sdf will be replaced
# with [MODEL_NAME]_[ID].
# A position can additionally be specified to choose where to place the given model.

def spawn_sdf(sdf_input, id : int = None, pos : tuple = (0, 0, 0), world_name : str =  WORLD_NAME):

    with open(sdf_input) as sdf_file:
        
        sdf_string = sdf_file.read()

        model_name = None

        # use re to look for the model name and save it
        model_name_pattern = r"<model\s+name='([^']+)'"
        match = re.search(model_name_pattern, sdf_string)
        if match:
            model_name = match.group(1)

        if model_name is None:
            raise Exception(f"Error while trying to parse model name from file {sdf_input}")
        

        # replace all the occurrences of model_name with model_name_id, and set the model name accordingly,
        # if an id was given
        if id is None:
            model_name_with_id = model_name
        else:
            sdf_string = sdf_string.replace(model_name, f"{model_name}_{id}")
            model_name_with_id = f"{model_name} - {id}"

        return Node(
                package='ros_gz_sim',
                executable='create',
                arguments= [
                    '-world',
                    world_name,
                    '-string',
                    sdf_string,
                    "-name",
                    model_name_with_id,
                    "-x",
                    str(pos[0]),
                    "-y",
                    str(pos[1]),
                    "-z",
                    str(pos[2])
                ],
                name='sim'
        )