import os
from glob import glob

from setuptools import find_packages, setup

package_name = 'project_main'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*_launch.[pxy][yma]*')),
        (os.path.join('lib', package_name), glob(package_name + '/*_utils.py*'))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='fede3751',
    maintainer_email='trombetti@di.uniroma1.it',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'simulation_manager=project_main.simulation_manager:main',
            'balloon_controller=project_main.balloon_controller:main',
            'sensor_controller=project_main.sensor_controller:main',
            'fleet_coordinator=project_main.fleet_coordinator:main'
        ],
    },
)
