#!/usr/bin/env python
# coding=utf-8

import json

key_word_dict={
    '自动化':'！在人类科技发展的历史进程中，自动化科学和技术始终占有重要地位和作用。早在20世纪50年代，清华大学就设置了与自动化学科有关的一批专业。1970年5月，学校将有关的专业联合归并，组建了国内第一个自动化系。',
    '马天云':'！真香！'

}

# with open("./word.json","w") as f:
#     json.dump(key_word_dict,f)
#     print("*****************")

with open("/home/robot/catkin_ws/src/xbchat/scripts/word.json","r") as f:
    key_dict = json.load(f)
for key in key_dict:
    key1 = key.encode('raw_unicode_escape')
    mess = key_dict[key].encode('unicode_escape')
    print(key1,mess)
    # print(key,key_dict[key])      
