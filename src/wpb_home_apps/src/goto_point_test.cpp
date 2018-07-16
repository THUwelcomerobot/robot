/*********************************************************************
* Software License Agreement (BSD License)
* 
*  Copyright (c) 2017-2020, Waterplus http://www.6-robot.com
*  All rights reserved.
* 
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
* 
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the WaterPlus nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
* 
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  FOOTPRINTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/
/* @author Zhang Wanjie                                             */

#include <ros/ros.h>
#include <std_msgs/String.h>
#include "goto_point.h"
// #include <String>
// #include <iostream>
// #include <csdtio>

static CGotoPoint goto_point_script;
static CGotoPoint speak_script;

int flag = 0;

// int FindName(String a,String b){

// }

void KeywordCB(const std_msgs::String::ConstPtr &msg)
{
    goto_point_script.Init();
    //ROS_WARN("[goto_point_script_KeywordCB] - %s",msg->data.c_str());
    // string strListen = msg->data;
    // goto_point_script.strListen = strListen;
    std_msgs::String strListen;
    std::cout << "[msg->data.find(0)]:" << msg->data.find("办公") << std::endl;
    if (msg->data.find("办公") == 0)
    // if (msg->data == "办公")

    {
        std::cout << msg->data;
        strListen.data = "办公室";
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@";
        goto_point_script.Queue(strListen);
        goto_point_script.ShowActs();
    }
    // else if (msg->data =="教室")
    else if (msg->data.find("教") == 0)
    {
        std::cout << msg->data << std::endl;
        strListen.data = "教室";
        std::cout << "$$$$$$$$$$$$$$$$$$$$" << strListen.data;
        goto_point_script.Queue(strListen);
        goto_point_script.ShowActs();
    }
    else
        return;
    int i = 0;
    while (i < 3)
    {
        goto_point_script.Main();
        i++;
    }
    goto_point_script.Reset();
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "goto_point_script");
    ROS_INFO("[main] goto_point_script");
    speak_script.Init();
    ros::NodeHandle n;
    ros::Rate r(10);
    // ros::Publisher mess_pub = n.advertise<std_msgs::String >("/xfyun/tts", 10);
    // std_msgs::String ques;
    // printf("start speak ################");
    // ques.data = "!我要出发了，你想让我去老师办公室还是教室呢";
    // mess_pub.publish(ques);
    // ros::spinOnce();
    // r.sleep();
    // ros::Subscriber sub_sr = n.subscribe("/xfyun/iat", 10, KeywordCB);
    // speak_script.SQueue();
    // speak_script.ShowActs();
    // while(ros::ok())
    // {
    //     speak_script.Main();
    //     ros::spinOnce();
    //     r.sleep();
    // }
    // while(flag==0)
    // {
    //     ros::spinOnce();
    //     r.sleep();
    // }
    ros::Subscriber cmd_sub = n.subscribe("/gosomewhere", 10, KeywordCB);
    ros::spin();
    return 0;
}