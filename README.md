#turtlebot_car 

This is a ROS catkin package that contains specific launch files (and other resources) to use the turtlebot with an hokuyo laser, gmapping and move_base

##Prerequisites / Installation

cf. INSTALL.md

##How to use

### Bringup + teleop
	
	roslaunch turtlebot_car bringup_minimal.launch
	
	# in a separate terminal you may run for manual control
	roslaunch kobuki_keyop keyop.launch

### Bringup + gmapping

	roslaunch turtlebot_car gmapping.launch 
	
	# in a separate terminal you may run for manual control
	roslaunch kobuki_keyop keyop.launch

### Bringup + move_base

	roslaunch turtlebot_car move_base.launch
	
	# in a separate terminal you may run for manual control
	roslaunch kobuki_keyop keyop.launch

### Bringup + gmapping + move_base

	roslaunch turtlebot_car bringup_gmapping.launch
	
	# in a separate terminal you may run for manual control
	roslaunch kobuki_keyop keyop.launch

### Autonomous exploration with Turtlebot

	# the following command runs phrontier_exploration (cf. INSTALL.md)
	# which publishes accessible frontiers to be explored 
	roslaunch simple_exploration simple_exploration_minimal.launch
	
	# this will send frontiers as goals to move_base
	rosrun simple_exploration simple_exploration

##Reminders

On the master machine: 

1. in a terminal run roscore
2. run whatever

On the remote:

1. `export ROS_MASTER_URI=http://ROS_MASTER_IP:11311`
2. run whatever
