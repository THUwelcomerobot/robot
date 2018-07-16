#!/usr/bin/env python
import rospy
from std_msgs.msg import String
rospy.init_node('go_to_listen')
rate = rospy.Rate(10)


def cmdpub(msg):
    cmd_publisher.publish(msg.data)


sound_sub = rospy.Subscriber('/xfyun/iat', String, callback=cmdpub)
cmd_publisher = rospy.Publisher('/gosomewhere', String, queue_size=10)
rospy.spin()
