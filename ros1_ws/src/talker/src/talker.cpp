#include "ros/ros.h"
#include "custom_msgs/Coord.h"

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<custom_msgs::Coord>("chatter", 1000);
  ros::Rate loop_rate(10);

  double count = 0;

  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    custom_msgs::Coord msg;
    count += 0.1;

    if (count > 10.0) {
        count = -10.0;
    }

    msg.x = count * 10;
    msg.y = count * count * 10;
    msg.z = count * count * count * 10;

    ROS_INFO("%d %d %d", msg.x, msg.y, msg.z);
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}