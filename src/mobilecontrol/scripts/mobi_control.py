#!/usr/bin/env python
# coding:utf-8
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist

linnear_vel = 0.3
angular_vel = 0.3
cmd = [
    '前', '后', '左', '右', '顺', '逆', '停',
]


def mobi_control(msg):
    global linnear_vel, angular_vel, cmd
    if cmd[0] in msg.data:
        cmd_msg.linear.x = linnear_vel
    elif cmd[1] in msg.data:
        cmd_msg.linear.x = -linnear_vel
    elif cmd[2] in msg.data:
        cmd_msg.linear.y = -linnear_vel
    elif cmd[3] in msg.data:
        cmd_msg.linear.y = linnear_vel
    elif cmd[4] in msg.data:
        cmd_msg.angular.z = angular_vel
    elif cmd[5] in msg.data:
        cmd_msg.angular.z = -angular_vel
    else:
        cmd_msg = Twist()


rospy.init_node('mobi_control')
cmd_msg = Twist()
instruction_getter = rospy.Subscriber(
    '/mobi_instruction', String, callback=mobi_control)
controller = rospy.Publisher('/cmd_vel', Twist, queue_size=2)
