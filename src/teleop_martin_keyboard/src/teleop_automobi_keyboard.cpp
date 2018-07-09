#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <tf/transform_listener.h>
class teleop_automobi{
private:
    ros::NodeHandle _nh;
    ros::Publisher _cmd_vel_pub;
    tf::TransformListener _listener;
public:
    teleop_automobi(ros::NodeHandle nh)
    {
        _nh=nh;
        _cmd_vel_pub=_nh.advertise<geometry_msgs::Twist>("/cmd_vel",10);
    }
    bool movForwardOdom(double distance )
    {
        _listener.waitForTransform("base_footprint","odom_combined",ros::Time(0),ros::Duration(1.0));
        tf::StampedTransform start_transform;
        tf::StampedTransform current_transform;
        _listener.lookupTransform("base_footprint","odom_combined",ros::Time(0),start_transform);
        geometry_msgs::Twist base_cmd;
        base_cmd.linear.y=base_cmd.angular.z=0;
        base_cmd.linear.x=1;
        ros::Rate rate(10.0);
        bool done = false;
        while(!done && _nh.ok())
        {
            _cmd_vel_pub.publish(base_cmd);
            rate.sleep();
        try{
            _listener.lookupTransform("base_footprint","odom_combined",ros::Time(0),current_transform);
        }
        catch(tf::TransformException ex)
        {
            ROS_ERROR("%s",ex.what());
            break;
        }
        tf::Transform relative_transform=start_transform.inverse()*current_transform;
        double dist_moved=relative_transform.getOrigin().length();
        if(dist_moved > distance) done=true; 
        }
        if(done) return true;
        return false;
    }
    bool keyboardloop()
    {
        std::cout<<"\npress 'w' to forward";
        std::cout<<"\npress 's' to backward";
        std::cout<<"\npress 'a' to turn left";
        std::cout<<"\npress 'd' to turn right\n";
        std::cout<<"\npress 'q' to stop\n";
        geometry_msgs::Twist cmd_msg;
        char cmd[50];
        while(_nh.ok())
        {
            std::cin.getline(cmd,50);
            if(cmd[0]!='w'&&cmd[0]!='a'&&cmd[0]!='d'&&cmd[0]!='s'&&cmd[0]!='q')
            {
                std::cout<<"unknown command:"<<cmd<<std::endl;
                continue;
            }
            cmd_msg.linear.x=cmd_msg.angular.z=cmd_msg.linear.y=0;
            switch(cmd[0])
            {
                case 'w':
                {
                cmd_msg.linear.x=0.2;
                cmd_msg.angular.z=0;
                break;
                }
                case 'a':
                {
                cmd_msg.linear.x=0;
                cmd_msg.angular.z=-0.2;
                break;
                }
                case 's':
                {
                cmd_msg.linear.x=-0.2;
                cmd_msg.angular.z=0;
                break;
                }
                case 'd':
                {
                cmd_msg.linear.x=0;
                cmd_msg.angular.z=0.2;
                break;
                case 'q':
                {
                    cmd_msg.linear.x=0;
                    cmd_msg.angular.z=0;
                    break;
                }
                default:
                {
                    cmd_msg.linear.x=0;
                    cmd_msg.angular.z=0;
                }
                }
            }
            _cmd_vel_pub.publish(cmd_msg);
        }
        return true;
    }
};

int main(int argc,char **argv)
{
    ros::init(argc,argv,"teleop_automobi_keyboard");
    ros::NodeHandle nh;
    teleop_automobi teleop_control(nh);
    // teleop_control.keyboardloop();
    teleop_control.movForwardOdom(1);
    ros::spin();
}