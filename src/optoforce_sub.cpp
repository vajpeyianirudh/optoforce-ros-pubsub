#include <iostream>
#include "optoforce_sensor/opto.h"
#include "ros/ros.h"
#include "geometry_msgs/WrenchStamped.h"
#include <unistd.h>
#include <string.h>

void subscriberCallback()
{
	ROS_INFO("", wrench_msg->);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "OForceSensorSubscriber");
	
	ros::NodeHandle n;
	
	ros::Subscriber wrench_sub_raw = n.subscribe("OptoForceWrench_raw", 1000, subscriberCallback);
	ros::subscriber wrench_sub = n.subscriber("OptoForceWrench", 1000, subscriberCallback);
	
	ros::spin();
	
	return 0;
}
