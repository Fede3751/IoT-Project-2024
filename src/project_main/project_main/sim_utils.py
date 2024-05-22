import os
import re
from typing import Callable, List

from launch_ros.actions import Node

from rosgraph_msgs.msg import Clock

WORLD_NAME = "iot_project_world"




def spawn_sdf(sdf_input, id : int = None, pos : tuple = (0, 0, 0), world_name : str =  WORLD_NAME):

    """
    Function used to dynamically spawn a new sdf object at the start of the simulation. Use this to spawn multiple times
    the same object with different ids in your launch file.
    This function additionally modifies all the occurrences of the model name inside the SDF, keeping plugins such as
    OdometryPublisher consistent even without namespaces set. All occurrences of [MODEL_NAME] inside the sdf will be replaced
    with [MODEL_NAME]_[ID].
    A position can additionally be specified to choose where to place the given model.

        sdf_input:
            the path to the sdf_file to spawn (relative to pwd or absolute)
        id:
            the id of the new model, should be different by all the ids of object with the same sdf
        pos:
            the position where to spawn the model
        world_name:
            the name of the world to spawn the model to
    """

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
    



DEFAULT_SCHEDULER_RATE = 10

class EventScheduler():

    """
    Class used to schedule timed events following a ROS2 Clock interface.

        rate:
            specify the rate at which events are checked, set by default to 10 checks
            per simulation seconds
    """


    def __init__(self, rate = DEFAULT_SCHEDULER_RATE):

        self.current_time = 0
        self.rate = rate
        self.scheduled_events = []


    def routine(self, clock : Clock):

        """
        Main method to update the scheduler. This method should be called every time
        the simulation clock updates.

            clock:
                the new time in the simulation
        """

        new_time = clock.clock.sec + clock.clock.nanosec * 10**(-9)

        # Before running through events, check for rate. This allows
        # to run through all the events at a desired frequency, without
        # wasting resources
        if new_time - self.current_time > 1/self.rate:
            self.current_time = new_time
        else:
            return

        # Loop through all the scheduled events
        for event in self.scheduled_events:

            # If the event time has passed, execute it
            if event['time'] + event['scheduled_time'] < self.current_time:
                
                event['callback'](*event['args'])

                if event['repeat']:
                    event['scheduled_time'] = self.current_time
                
                else:
                    self.scheduled_events.remove(event)

    
    # Schedule a new event in the scheduler. 
    def schedule_event(self, time : float, callback : Callable, repeat = True, args : list = []):

        """
        Schedule a new event in the EvenScheduler.

            time:
                timeout to the event in seconds
            callback:
                the function to execute when the time expires
            repeat:
                if True, the event is repeated at the frequency given by time
            args:
                argument to pass to the callback function
        """

        self.scheduled_events.append(
            {
                'time': time,
                'callback': callback,
                'repeat' : repeat,
                'args' : args,

                'scheduled_time' : self.current_time,

            }
        )