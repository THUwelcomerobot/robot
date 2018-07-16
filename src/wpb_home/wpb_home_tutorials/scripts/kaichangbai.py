#!/usr/bin/env python
#coding:utf-8

import rospy
from std_msgs.msg import String

msg="很高兴见到你，我是来自清华大学自动化系的迎新机器人小U，在人类科技发展的历史进程中，\
自动化科学和技术始终占有重要地位和作用。早在20世纪50年代，清华大学就设置了与自动化学科有关的一批专业。\
1970年5月，学校将有关的专业联合归并，组建了国内第一个自动化系。经过30多年的发展，自动化系在教学和科研上取得了丰硕的成果，\
为我国培养了大批的学士、硕士和博士，成为我国自动化科学与技术的重要研究和开发基地、培养自动化领域各层次高级专门人才的摇篮，\
在我国现代化建设中发挥了重要作用。为了适应新技术革命和社会主义市场经济的需要，进一步加强基础，拓宽专业面向，从1993级开始，\
自动化系本科只设“自动化”一个专业。"
new_msg='很高兴见到你，我是来自清华大学自动化系的迎新机器人小U，在人类科技发展的历史进程中'
print(msg)
rospy.init_node('kaichangbai')
rate=rospy.Rate(100)
# rate.sleep()
start_pub=rospy.Publisher('/xfyun/tts',String,queue_size=1)
if not rospy.is_shutdown():
    start_pub.publish(msg)        
    rospy.sleep(0.25)
    start_pub.publish(msg)
    # rospy.sleep(5)