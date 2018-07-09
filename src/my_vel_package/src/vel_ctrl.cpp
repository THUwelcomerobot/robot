#include <ros/ros.h>

#include <geometry_msgs/Twist.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "vel_ctrl");

    ros::NodeHandle n;

    ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    while(ros::ok())
    {
        geometry_msgs::Twist vel_cmd;

        vel_cmd.linear.x = 0.2;
        vel_cmd.linear.y = 0;
        vel_cmd.linear.z = 0;

        vel_cmd.angular.x = 0;
        vel_cmd.angular.y = 0;
        vel_cmd.angular.z = 0;

        vel_pub.publish(vel_cmd);

        ros::spinOnce();
    }

    return 0;
}