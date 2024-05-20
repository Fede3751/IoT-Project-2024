from setuptools import find_packages
from setuptools import setup

setup(
    name='project_interfaces',
    version='1.0.0',
    packages=find_packages(
        include=('project_interfaces', 'project_interfaces.*')),
)
