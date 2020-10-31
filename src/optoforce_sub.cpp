#include <iostream>
#include "ros/ros.h"
#include "geometry_msgs/WrenchStamped.h"
#include <string.h>

// Two methods of writing Callback functions and different methods of using ROS_INFO and ROS_INFO_STREAM

//void subscriberCallback(const geometry_msgs::WrenchStamped wrench_msg)
//{
	//ROS_INFO_STREAM("Fx: " << wrench_msg.wrench.force.x << " Fy: " << wrench_msg.wrench.force.y << " Fz: " << wrench_msg.wrench.force.z << " Tx: " << wrench_msg.wrench.torque.x << " Ty: " << wrench_msg.wrench.torque.y << " Tz: " << wrench_msg.wrench.torque.z);
//	ROS_INFO("Fx: %f Fy: %f", wrench_msg.wrench.force.x, wrench_msg.wrench.force.y);
//}

void subscriberCallback(const geometry_msgs::WrenchStamped::ConstPtr& wrench_msg)
{
        //ROS_INFO_STREAM("Fx: " << wrench_msg.wrench.force.x << " Fy: " << wrench_msg.wrench.force.y << " Fz: " << wrench_msg.wrench.force.z << " Tx: " << wrench_msg.wrench.torque.x << " Ty: " << wrench_msg.wrench.torque.y << " Tz: " << wrench_msg.wrench.torque.z);
        ROS_INFO("Fx: %f Fy: %f Fz: %f \n\n\t\t\t\tTx: %f Ty: %f Tz: %f\n", wrench_msg->wrench.force.x, wrench_msg->wrench.force.y, wrench_msg->wrench.force.z, wrench_msg->wrench.torque.x, wrench_msg->wrench.torque.y, wrench_msg->wrench.torque.z);
}


int main(int argc, char **argv)
{
	ros::init(argc, argv, "OForceSensorSubscriber");
	
	ros::NodeHandle n;
	
	ros::Subscriber wrench_sub_raw = n.subscribe("OptoForceWrench_raw", 1000, subscriberCallback);
	ros::Subscriber wrench_sub = n.subscribe("OptoForceWrench", 1000, subscriberCallback);
	
	ros::spin();
	
	return 0;
}
