#!/usr/bin/env python
# coding=utf-8
import rospy
import itchat
import threading
from std_msgs.msg import String

username = None

# class MyThread(Thread):
#     def __init__(self,name,count):
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
        print(show)
        mess_publisher.publish(show)

@itchat.msg_register(itchat.content.ATTACHMENT, isMpChat=True)
def att_reply(msg):
    if msg.FromUserName == username:
        show ="我暂时没法唱给你听" 
        mess_publisher.publish(show)


@itchat.msg_register(itchat.content.SHARING, isMpChat=True)
def att_reply1(msg):
    if msg.FromUserName == username:
        show ="我暂时没法唱给你听" 
        mess_publisher.publish(show)

def messsend(msg):
    global username    
    print('[message from the person]:'+msg.data)
    SendText = unicode(msg.data, "utf-8")
    itchat.send(SendText, toUserName=username)


# def messget(msg):
#     out_msg = '  '+msg.data
#     print('[message from xiaobing]:'+msg.data)
#     mess_publisher.publish(out_msg)
#########
# output:/xbinput


#########
rospy.init_node('messtoxb')
iat_sub = rospy.Subscriber('/xfyun/iat', String, callback=messsend)
# mess_suber = rospy.Subscriber('/xboutput', String, callback=messget)
mess_publisher = rospy.Publisher('/xfyun/tts', String, queue_size=1)
name = unicode("小冰", "utf-8")
itchat.auto_login(hotReload=False)
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
