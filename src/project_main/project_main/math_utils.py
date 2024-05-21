import math

from geometry_msgs.msg import Point


def angle_between_points(p0 : Point, p1 : Point) -> float:

    '''
    Computes the angle between the two given points, in radiants.
    p0: the coordinates of the first point (x0, y0)
    p1: the coordinates of the second point (x1, y1)
    '''

    vector_between = (p1.x - p0.x, p1.y - p0.y)

    norm = math.sqrt(vector_between[0] ** 2 + vector_between[1] ** 2)
    direction = (vector_between[0] / norm, vector_between[1] / norm)

    return math.atan2(direction[0], direction[1]) % (math.pi * 2)


def point_distance(p0 : Point, p1 : Point) -> float:

    vec = (p1.x - p0.x, p1.y - p0.y, p1.z - p0.z)
    return math.sqrt(vec[0]**2 + vec[1]**2 + vec[2]**2)


def move_vector(p0 : Point, p1 : Point) -> tuple[float, float]:

    vec = (math.sqrt((p1.x - p0.x)**2 + (p1.y - p0.y)**2), p1.z - p0.z)
    norm = math.sqrt(vec[0]**2 + vec[1]**2)

    return (vec[0]/norm, vec[1]/norm)


def euler_from_quaternion(x : float, y : float, z : float, w : float) -> tuple[float, float, float]:
    
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

def get_yaw(x, y, z, w) -> float:
    return euler_from_quaternion(x,y,z,w)[2] % (math.pi * 2)
