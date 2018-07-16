#!/usr/bin/env python
# coding=utf-8
import rospy
import itchat
import re
import json
from geometry_msgs.msg import Twist
from std_msgs.msg import String


key_word_dict={
    '自动化':'！在人类科技发展的历史进程中，自动化科学和技术始终占有重要地位和作用。早在20世纪50年代，清华大学就设置了与自动化学科有关的一批专业。组建了国内第一个自动化系。',
    '马天云':'！真香！',
    '于沛':'！真香！',
    '刘启涵':'！真香！',
    '郝敏升':'！真香！',    
    '同学':'！个个都是人才，说话又好听',
    '钱':'！有钱真的可以为所欲为',
    '教室':'！进教室跟回家一样。唷呼，超喜欢在这里的',
    '学习':'!too simple!',
}







# cmd_vel_linear
cmd_vel_linear = 0.2
# cmd_vel_angular
cmd_vel_angular = 0.2
# cmd_vel
cmd_vel = [
    ('向前走', cmd_vel_linear, 0, 0),
    ('向后退', -cmd_vel_linear, 0, 0),
    ('向左移', 0, cmd_vel_linear, 0),
    ('向右移', 0, -cmd_vel_linear, 0),
    ('向左转', 0, 0, cmd_vel_angular),
    ('向右转', 0, 0, -cmd_vel_angular),
    ('停下来', 0, 0, 0),
]
#
# cmd_twist
cmd_twist = Twist()

username = None
# class MyThread(Thread):
#     def __init__(self,nunt):
#         super(MyThread,self).__init__()
#     def run(self):
#         print('runaa############')
#         itchat.run()
global mess_publisher


@itchat.msg_register(itchat.content.TEXT, isMpChat=True)
def text_reply(msg):
    global username
    # print("^^^^^^^^^")
    if msg.FromUserName == username:
        show = msg.Text
        show = re.sub(r'\[.*\]','',show)
        show = re.sub(r'\(.*\)','',show)
        show = '!!!' + show
        print(show)
        mess_publisher.publish(show)


@itchat.msg_register(itchat.content.ATTACHMENT, isMpChat=True)
def att_reply(msg):
    if msg.FromUserName == username:
        show = "我暂时没法唱给你听"
        mess_publisher.publish(show)


@itchat.msg_register(itchat.content.SHARING, isMpChat=True)
def att_reply1(msg):
    if msg.FromUserName == username:
        show = "我暂时没法唱给你听"
        mess_publisher.publish(show)


def messsend(msg):
    global username
    flag=False
    print(type(msg.data))
    for (cmd, x, y, z) in cmd_vel:
        if msg.data == cmd:
            flag=True
            print(cmd)
            cmd_move(x, y, z)
            break
    for key in key_word_dict:
        # key1 = key.decode('unicode_escape')
        mess = key_word_dict[key]
        print(key,mess)        
        if msg.data.find(key)>=0:
            mess_publisher.publish(mess)
            print("okokokokokok")
            flag=True
            break

    if not flag:
        print('[message from the person]:'+msg.data)
        SendText = unicode(msg.data, "utf-8")
        itchat.send(SendText, toUserName=username)


def cmd_move(linear_x, linear_y, angular_z):
    cmd_twist.linear.x = linear_x
    cmd_twist.linear.y = linear_y
    cmd_twist.angular.z = angular_z
    last_time=rospy.Time.now()
    cmd_publisher.publish(cmd_twist)
    rate.sleep()
    now_time=rospy.Time.now()
    dur = now_time.to_sec()-last_time.to_sec()
    while dur<2:
        now_time = rospy.Time.now()
        dur = now_time.to_sec()-last_time.to_sec()    
    print(now_time.to_sec()-last_time.to_sec())
    cmd_twist_empty=Twist()
    cmd_publisher.publish(cmd_twist_empty)
# def messget(msg):
#     out_msg = '  '+msg.data
#     print('[message from xiaobing]:'+msg.data)
#     mess_publisher.publish(out_msg)
#########
# output:/xbinput


#########
rospy.init_node('messtoxb')
rate=rospy.Rate(0.5)
iat_sub = rospy.Subscriber('/xfyun/iat', String, callback=messsend)
# mess_suber = rospy.Subscriber('/xboutput', String, callback=messget)
mess_publisher = rospy.Publisher('/xfyun/tts', String, queue_size=1)
cmd_publisher = rospy.Publisher('/cmd_vel', Twist, queue_size=1)
name = unicode("小冰", "utf-8")
itchat.auto_login(hotReload=True)
res_dicList = itchat.search_mps(name=name)
username = res_dicList[0].UserName
itchat.run(blockThread=False)
# itchat_thread=Thread()
# itchat_thread.start()
# itchat_thread=threading.Thread(target=itchat.run())
# itchat_thread.start()
print('####')
rospy.spin()
# itchat_thread.join()
