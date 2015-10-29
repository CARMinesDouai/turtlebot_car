To run the node you need to have the following packages installed

1. Install ubuntu 14.04
2. Install ROS indigo		
3. Install hokuyo\_node for hokuyo URG-04LX-UG01
	* This node provide the topic /scan from the URG laser
	* from binaries: `sudo apt-get install ros-indigo-hokuyo-node`
	* from sources:

	```bash
	# Generic way to install a catkin package from sources
	cd ~/catkin_ws/src
	git clone https://github.com/ros-drivers/hokuyo_node.git
	cd ~/catkin_ws
	catkin_make
	```	
4. Install kobuki package kobuki_node 
	* from binaries as ROS packages : http://wiki.ros.org/kobuki/Tutorials/Installation
	* or from sources https://github.com/yujinrobot/kobuki.git (Same steps above)
5. Ensure turtle_tf package is installed
	* This node provides the transformation from "laser" to "base_link" frame
6. Run `rosrun kobuki_ftdi create_udev_rules` before plugging in the kobuki
7. Install gmapping and move_base

	```bash
		sudo apt-get install ros-indigo-gmapping ros-indigo-move-base
	```
8. Add current user to dialout and restart the machine

	```bash
		sudo usermod -a -G dialout dev 
	```
9. Install the catkin package turtlebot_car
	* https://github.com/CARMinesDouai/turtlebot_car.git (Same steps above)
	* the provided launch file turtlebot_minimal.launch launches the hokuyo_node with specific paramaters that set up larger values for the min and the max angles (more than 180deg)

10. Install PhaROS

	```bash
	curl http://car.mines-douai.fr/scripts/Robulab | bash
	```
11. Install PhrontierExploration PhaROS package
	
	```bash
	pharos create phrontier_exploration
	rosrun edit phrontier_exploration
	# load this package: http://smalltalkhub.com/#!/~CAR/PhrontierExploration
	```
11. Install simple_exploration 
	* https://github.com/CARMinesDouai/simple_exploration.git (Same steps above)

11. cf. README.md for the usage
