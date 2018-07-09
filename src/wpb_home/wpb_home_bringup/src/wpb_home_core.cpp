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
/*!******************************************************************
 @author     ZhangWanjie
 ********************************************************************/

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/Twist.h>
#include "driver/WPB_Home_driver.h"
#include <math.h>

static CWPB_Home_driver m_wpb_home;
static int nLastMotorPos[3];
void cmdVelCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
    //ROS_INFO("[wpb_home] liner(%.2f %.2f) angular(%.2f)", msg->linear.x,msg->linear.y,msg->angular.z);
    m_wpb_home.Velocity(msg->linear.x,msg->linear.y,msg->angular.z);
}

static float fKVx = 1.0f/sqrt(3.0f);
static float fKVy = 2.0f/3.0f;
static float fKVz = 1.0f/3.0f;
static float fSumX =0;
static float fSumY =0;
static float fSumZ =0;
static float fOdomX =0;
static float fOdomY =0;
static float fOdomZ =0;
static geometry_msgs::Pose2D lastPose;
static geometry_msgs::Twist lastVel;
int main(int argc, char** argv)
{
    ros::init(argc,argv,"wpb_home_core");
    ros::NodeHandle n;
    ros::Subscriber cmd_vel_sub = n.subscribe("cmd_vel",10,&cmdVelCallback);
    ros::Publisher imu_pub = n.advertise<sensor_msgs::Imu >("imu/data_raw", 100);

    ros::NodeHandle n_param("~");
    std::string strSerialPort;
    n_param.param<std::string>("serial_port", strSerialPort, "/dev/ttyUSB0");
    m_wpb_home.Open(strSerialPort.c_str(),115200);

    bool bImuOdom;
    n_param.param<bool>("imu_odom", bImuOdom, false);
    
    ros::Time current_time, last_time;
    current_time = ros::Time::now();
    last_time = ros::Time::now();
    ros::Rate r(100.0);

    ros::Publisher odom_pub;
    geometry_msgs::TransformStamped odom_trans;
    tf::TransformBroadcaster broadcaster;
    nav_msgs::Odometry odom;
    geometry_msgs::Quaternion odom_quat;

    odom_pub = n.advertise<nav_msgs::Odometry>("odom",2);
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_footprint";
    odom.header.frame_id = "odom";
    odom.child_frame_id = "base_footprint";
    odom_trans.transform.translation.x = 0;
    odom_trans.transform.translation.y = 0;
    odom_trans.transform.translation.z = 0;
    odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(0);
    odom.pose.pose.position.x = 0;
    odom.pose.pose.position.y = 0;
    odom.pose.pose.position.z = 0.0;
    odom.pose.pose.orientation = odom_quat;
    odom.twist.twist.linear.x = 0;
    odom.twist.twist.linear.y = 0;
    odom.twist.twist.linear.z = 0;
    odom.twist.twist.angular.x = 0;
    odom.twist.twist.angular.y = 0;
    odom.twist.twist.angular.z = 0;

    lastPose.x = lastPose.y = lastPose.theta = 0;
    lastVel.linear.x = lastVel.linear.y = lastVel.linear.z = lastVel.angular.x = lastVel.angular.y = lastVel.angular.z = 0;
    nLastMotorPos[0] = nLastMotorPos[1] = nLastMotorPos[2] = 0;
    while(n.ok())
    {
        m_wpb_home.ReadNewData();
        m_wpb_home.nParseCount ++;
        //ROS_INFO("[m_wpb_home.nParseCount]= %d",m_wpb_home.nParseCount);
        if(m_wpb_home.nParseCount > 100)
        {
            m_wpb_home.arMotorPos[0] =0; nLastMotorPos[0] = 0;
            m_wpb_home.arMotorPos[1] =0; nLastMotorPos[1] = 0;
            m_wpb_home.arMotorPos[2] =0; nLastMotorPos[2] = 0;
            m_wpb_home.nParseCount = 0;
            //ROS_INFO("empty");
        }
        
        last_time = current_time;
        current_time = ros::Time::now();

        if(bImuOdom == false)
        {
            double fVx,fVy,fVz;
            double fPosDiff[3];
            if(nLastMotorPos[0] != m_wpb_home.arMotorPos[0] || nLastMotorPos[1] != m_wpb_home.arMotorPos[1] || nLastMotorPos[2] != m_wpb_home.arMotorPos[2])
            {
                fPosDiff[0] = (double)(m_wpb_home.arMotorPos[0] - nLastMotorPos[0]); 
                fPosDiff[1] = (double)(m_wpb_home.arMotorPos[1] - nLastMotorPos[1]);
                fPosDiff[2] = (double)(m_wpb_home.arMotorPos[2] - nLastMotorPos[2]);
                
                fVx = (fPosDiff[1] - fPosDiff[0]) * fKVx;
                fVy = (fPosDiff[0] + fPosDiff[1]) - (fPosDiff[0] + fPosDiff[1] + fPosDiff[2])*fKVy;
                fVz = (fPosDiff[0] + fPosDiff[1] + fPosDiff[2])*fKVz;
                double fTimeDur = current_time.toSec() - last_time.toSec();
                fVx = fVx/(fTimeDur*9700);
                fVy = fVy/(fTimeDur*9700);
                fVz = fVz/(fTimeDur*1925);
                
                double dx = (lastVel.linear.x*cos(lastPose.theta) - lastVel.linear.y*sin(lastPose.theta))*fTimeDur;
                double dy = (lastVel.linear.x*sin(lastPose.theta) + lastVel.linear.y*cos(lastPose.theta))*fTimeDur;

                lastPose.x += dx;
                lastPose.y += dy;
                lastPose.theta += (fVz*fTimeDur);

                odom_quat = tf::createQuaternionMsgFromRollPitchYaw(0,0,lastPose.theta);
                //updata transform
                odom_trans.header.stamp = current_time;
                odom_trans.transform.translation.x = lastPose.x;
                odom_trans.transform.translation.y = lastPose.y;
                odom_trans.transform.translation.z = 0;
                odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(lastPose.theta);

                //filling the odometry
                odom.header.stamp = current_time;
                //position
                odom.pose.pose.position.x = lastPose.x;
                odom.pose.pose.position.y = lastPose.y;
                odom.pose.pose.position.z = 0.0;
                odom.pose.pose.orientation = odom_quat;

                //velocity
                odom.twist.twist.linear.x = fVx;
                odom.twist.twist.linear.y = fVy;
                odom.twist.twist.linear.z = 0;
                odom.twist.twist.angular.x = 0;
                odom.twist.twist.angular.y = 0;
                odom.twist.twist.angular.z = fVz;

                //plublishing the odometry and new tf
                broadcaster.sendTransform(odom_trans);
                odom_pub.publish(odom);

                lastVel.linear.x = fVx;
                lastVel.linear.y = fVy;
                lastVel.angular.z = fVz;

                nLastMotorPos[0] = m_wpb_home.arMotorPos[0];
                nLastMotorPos[1] = m_wpb_home.arMotorPos[1];
                nLastMotorPos[2] = m_wpb_home.arMotorPos[2];
            }
            else
            {
                odom_trans.header.stamp = ros::Time::now();
                //plublishing the odometry and new tf
                broadcaster.sendTransform(odom_trans);
                odom_pub.publish(odom);
                //ROS_INFO("[odom] zero");
            }
        }
        else
        {
            //imu
            sensor_msgs::Imu imu_msg = sensor_msgs::Imu();	
            imu_msg.header.stamp = ros::Time::now();
            imu_msg.header.frame_id = "imu";
            imu_msg.orientation.x = m_wpb_home.fQuatX;
            imu_msg.orientation.y = m_wpb_home.fQuatY;
            imu_msg.orientation.z = m_wpb_home.fQuatZ;
            imu_msg.orientation.w = m_wpb_home.fQuatW;

            imu_msg.angular_velocity.x = m_wpb_home.fGyroX;
            imu_msg.angular_velocity.y = m_wpb_home.fGyroY;
            imu_msg.angular_velocity.z = m_wpb_home.fGyroZ;

            imu_msg.linear_acceleration.x = m_wpb_home.fAccX;
            imu_msg.linear_acceleration.y = m_wpb_home.fAccY;
            imu_msg.linear_acceleration.z = m_wpb_home.fAccZ;

            imu_pub.publish(imu_msg);
        }

        ros::spinOnce();
        r.sleep();
    }
}