#include "take_photo.h"

CTakePhoto::CTakePhoto()
{
}
CTakePhoto::~CTakePhoto()
{
}

void CTakePhoto::Queue()
{
    stAct newAct;

    start_msg = "照相开始啦，，请站到我的摄像机的前方五米处，我会倒计时五秒，对我说准备好了我就开始倒计时啦";
    newAct.nAct = ACT_SPEAK;
    newAct.strTarget = start_msg;
    newAct.nDuration = 5;
    arAct.push_back(newAct);

    newAct.nAct = ACT_LISTEN;
    newAct.strTarget = "准备好";
    newAct.nDuration = 5;
    arAct.push_back(newAct);

    newAct.nAct = ACT_SPEAK;
    newAct.strTarget = "好的";
    newAct.nDuration = 5;
    arAct.push_back(newAct);

    for (int dec_sec = 5; dec_sec > 0; dec_sec--)
    {
        newAct.nAct = ACT_SPEAK;
        switch (dec_sec)
        {
        case 5:
            newAct.strTarget = "五";
        case 4:
            newAct.strTarget = "四";
        case 3:
            newAct.strTarget = "三";
        case 2:
            newAct.strTarget = "二";
        case 1:
            newAct.strTarget = "一";
        }
        newAct.nDuration = 1;
        arAct.push_back(newAct);
    }

    newAct.nAct = ACT_CAP_IMAGE;
    newAct.strTarget = "/home/robot/photos/new.png";
    newAct.nDuration = 1;
    arAct.push_back(newAct);

    
    newAct.nAct = ACT_SPEAK;
    newAct.strTarget = "我拍好啦";
    newAct.nDuration = 5;
    arAct.push_back(newAct);

    
}