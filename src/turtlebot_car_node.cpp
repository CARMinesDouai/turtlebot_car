/*
The MIT License (MIT)

Copyright (c) 2015 khelifa Baizid (khelifa.baizid@mines-douai.fr, baizid.khelifa@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>

//odometry topic name
std::string mOdometry_topic_name;

void odometryCallback(const nav_msgs::Odometry::ConstPtr& msg){
  //transform from the base_link to odom frame
  static tf::TransformBroadcaster br;
  tf::Transform transform;
  transform.setOrigin( tf::Vector3(msg->pose.pose.position.x, msg->pose.pose.position.y, 0.0) );
  tf::Quaternion q(0,0,msg->pose.pose.orientation.z,msg->pose.pose.orientation.w);

  transform.setRotation(q);
  br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "/odom", "/base_link"));
}

int main(int argc, char** argv){
  ros::init(argc, argv, "turtlebot_car");
  
  ros::NodeHandle nh;
  ros::NodeHandle private_nh("~");

  //we get the name of the odometry topic
  private_nh.getParam("odometry_topic_name", mOdometry_topic_name);
  mOdometry_topic_name = "/odom";
  //we define the subscriber to odometry
  ros::Subscriber sub = nh.subscribe<nav_msgs::Odometry>(mOdometry_topic_name, 10, &odometryCallback);

  std::cout<<"***************[ STARING turtlebot_car_node]***************** "<<std::endl;

  ros::spin();
  return 0;
};
