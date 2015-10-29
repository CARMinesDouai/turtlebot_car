#turtlebot_car 

This is a ROS catkin package that contains specific launch files (and other resources) to use the turtlebot with an hokuyo laser, gmapping and move_base

##Prerequisites / Installation

cf. INSTALL.md

##How to use

1. turtlebot tf
	* roslaunch turtlebot_car bringup_minimal.launch
	* in a separate terminal you may run for manual control: roslaunch kobuki_keyop keyop.launch to move the robot

2. turtlebot gmapping
	* roslaunch turtlebot_car gmapping.launch 
	* in a separate terminal you may run for manual control: roslaunch kobuki_keyop keyop.launch to move the robot

3. turtlebot move base
	* roslaunch turtlebot_car move_base.launch 
	* in a separate terminal you may run for manual control: roslaunch kobuki_keyop keyop.launch to move the robot

4. to launch all previous nodes ones: This will brings up the robot, and run hokuyo_node for the laser topic and gmapping and move_base
```bash
roslaunch turtlebot_car bringup_gmapping.launch (all nodes will be launched on the same machine)
```

5. For exploration 
	* roslaunch simple_exploration simple_exploration_minimal.launch (this runs phrontier_exploration and publish some accessible frontiers to be explored)
	* rosrun simple_exploration simple_exploration (this will send frontiers as goals to move_base)

REMOTE: make sure that your machines are connected 

On the master machine: 

1. in a terminal run roscore
2. run whatever

On the remote:

1. export ROS_MASTER_URI=http://ROS_MASTER_IP:11311
2. run whatever

ENJOY!

