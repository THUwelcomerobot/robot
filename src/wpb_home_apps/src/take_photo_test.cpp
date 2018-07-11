#include <ros/ros.h>
#include <std_msgs/String.h>
#include "take_photo.h"

static CTakePhoto:take_photo_script;

void KeywordCB(const std_msgs::String::ConstPtr & msg)
{
    //ROS_WARN("[home_script_KeywordCB] - %s",msg->data.c_str());
    string strListen = msg->data;
    take_photo_script.strListen = strListen;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "take_photo_script");
    ROS_INFO("[main] take_photo_script");
    take_photo_script.Init();
    take_photo_script.Queue();
    take_photo_script.ShowActs();

    ros::NodeHandle n;
    ros::Subscriber sub_sr = n.subscribe("/xfyun/iat", 10, KeywordCB);
    ros::Rate r(10);
    ros::spinOnce();
    while(ros::ok())
    {
        home_script.Main();
        ros::spinOnce();
        r.sleep();
    }

    return 0;
}