#!/usr/bin/env python
#coding:utf-8
import rospy 
from f_rec import DetXRec
from sensor_msgs.msg import Image
from std_msgs.msg import String

def facedetect(face_save_flag):
    # if not face_save_flag.data=='saved':
        # return 
    print('[face_compre]:yes saved!')
    namedic={
        # '2016011417':'马天云',
        # 'lqh':'刘启涵',
        '2016011000':'仁艳频老师',
        # 'ypy':'于沛钰',
        # '2016011493':'郝敏升',
    }
    templates=[]
    for key in namedic.keys():
        templates.append(key)
    # print(templates)
    instance=DetXRec(templates)
    instance.compare_faces('/home/robot/face_image/unknown.png')
    name_key=instance.whoIsThis()
    print(name_key)
    try:
        for key in namedic.keys():
            if name_key[0] == key:
                name=namedic[key]
                # print(name)
                name_pub.publish(name)
    except IndexError:
        pass
rospy.init_node('face_compare')
face_save=rospy.Subscriber('face_saved',String,callback=facedetect)
name_pub=rospy.Publisher('name_trans',String,queue_size=20)
rospy.spin()