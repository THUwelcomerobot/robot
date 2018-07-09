#!/usr/bin/env python
#  coding=utf-8
import rospy
import itchat
from std_msgs.msg import String


@itchat.msg_register(itchat.content.TEXT, isMpChat=True)
def text_reply(msg):
    if msg.FromUserName == UserName:
        show = unicode(msg.Text, "utf-8")
        print(show)


def messget(msg):
    out_msg = '  '+msg.data
    print('[message from xiaobing]:'+msg.data)
    mess_publisher.publish(out_msg)

###########
# input:/xboutput


##########
# itchat.auto_login(hotReload=True)
name = unicode("小冰", "utf-8")
res_dicList = itchat.search_mps(name=name)
UserName = res_dicList[0].UserName
itchat.run()
rospy.init_node('messfromxb')
mess_suber = rospy.Subscriber('/xboutput', String, callback=messget)
mess_publisher = rospy.Publisher('/xfyun/tts', String, queue_size=2)
rospy.spin()
