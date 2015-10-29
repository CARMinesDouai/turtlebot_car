#turtlebot_car 

This is a ROS catkin package that contains specific launch files (and other resources) to use the turtlebot with an hokuyo laser, gmapping and move base

## Installation
	
cf. INSTALL.txt

##Prerequisites

1. Make sure that you have hokuyo_node for hokuyo URG-04LX-UG01 (see INSTALL.txt)
	* This node provide the topic /scan from the URG laser
	* We modified the turtlebot_tf_minimal.launch to launch the hokuyo_node with new paramaters that fix lager values for the min and the max angles (more than 180deg)
	
2. Make sure that you have turtle_tf package (see INSTALL.txt)
	* This node provides the transformation from "laser" to "base_link" frame, you can define all parametres that are necessary of your URG pose and odometry topic in the launch file turtlebot_tf_minimal_real.launch.

##How to use

1. turtlebot tf
	* roslaunch turtlebot_tf turtlebot_tf_minimal.launch
	* in a separate terminal you may run for manual control: roslaunch kobuki_keyop keyop.launch to move the robot

2. turtlebot gmapping
	* roslaunch turtlebot_tf gmapping.launch 
	* in a separate terminal you may run for manual control: roslaunch kobuki_keyop keyop.launch to move the robot

3. turtlebot move base
	* roslaunch turtlebot_tf move_base.launch 
	* in a separate terminal you may run for manual control: roslaunch kobuki_keyop keyop.launch to move the robot

4. to launch all previous nodes ones: This will brings up the robot, and run hokuyo_node for the laser topic and gmapping and move_base
	* roslaunch turtlebot_tf turtlebot_tf_all.launch (all needs will be launch in the same machine)

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

