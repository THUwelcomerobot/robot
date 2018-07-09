#!/usr/bin/env python 
#coding:utf-8
import rospy
from sound_play.msg import SoundRequest
from std_msgs.msg import String

flag=True #接收名字状态
def feedback(msg):
    print('board_cast'+msg.data)
    global flag
    if flag == True:
        greet_msg=' 你好 '+msg.data
        tts_pub.publish(greet_msg)
    last_name=msg.data
    if last_name == msg.data:
        flag=False
    else:
        flag=True
        

rospy.init_node('name_boardcast')
tts_pub = rospy.Publisher('/xfyun/tts', String, queue_size=20)
rospy.Rate(0.2)
name_sub=rospy.Subscriber('/name_trans',String,callback=feedback)
rospy.spin()