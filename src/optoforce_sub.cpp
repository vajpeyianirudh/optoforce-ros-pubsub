#include <iostream>
#include <sstream>
#include "optoforce_sensor/opto.h"
#include "ros/ros.h"
#include "geometry_msgs/WrenchStamped.h"
#include "std_msgs/String.h"
#include <string.h>

void subscriberCallback(const std_msgs::String::ConstPtr& msg)
{
	//ROS_INFO("%f /n", wrench_msg->wrench.force.x);
	ROS_INFO("%s", msg->data.c_str());
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "OForceSensorSubscriber");
	
	ros::NodeHandle n;
	
	ros::Subscriber wrench_sub_raw = n.subscribe("OptoForceWrench_raw", 1000, subscriberCallback);
	ros::Subscriber wrench_sub = n.subscribe("OptoForceWrench", 1000, subscriberCallback);
	ros::Subscriber wrench_sub_str = n.subscribe("OptoForceWrench_str", 1000, subscriberCallback);
	
	ros::spin();
	
	return 0;
}
