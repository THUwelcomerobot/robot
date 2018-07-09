#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def feedback(msg):
    print(msg.data)
rospy.init_node('sound_rec_sub')
sub=rospy.Subscriber('/xfyun/iat',String,callback=feedback)
rospy.spin()