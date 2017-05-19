#include "ros/ros.h"
#include "geometry_msgs/PoseStamped"


void callBack(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
	geometry_msgs::Point mapData = msg->info;
  	ROS_INFO("I'm connecting to the geometry message listener");
  	ROS_INFO("The x is: %u" , mapData.x);
  	ROS_INFO("The y is: %u", mapData.y);
  ROS_INFO("-------------------------");
}

int main (int argc, char **argv)
{
	ros::init(argc, argv, "map_listener");
	ros::NodeHandle nodeH;
	ros::Subscriber sub = nodeH.subscribe("map", 1000, 		callBack); //dont think it checks more than once, so 		this must be ran after hector_slam's map node has been 		ran
	ros::spin();
}
