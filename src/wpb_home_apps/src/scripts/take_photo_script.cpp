#include "take_photo.h"
#include <string>

CTakePhoto::CTakePhoto()
{
}
CTakePhoto::~CTakePhoto()
{
}

void CTakePhoto::Queue()
{
    stAct newAct;
    // newAct.nAct = ACT_LISTEN;
    // newAct.strTarget = "照相";
    // newAct.nDuration = 5;
    // arAct.push_back(newAct);

    newAct.nAct = ACT_MOVE;
    newAct.fLinear_x = 0;
    newAct.fLinear_y = 0;
    newAct.fAngular_z = 0;
    newAct.nDuration = 1;
    arAct.push_back(newAct);

    string start_msg = "照相开始啦，，请站到我的摄像机的前方一米处，我会倒计时五秒，对我说准备好了我就开始倒计时啦";
    newAct.nAct = ACT_SPEAK;
    newAct.strTarget = start_msg;
    newAct.nDuration = 15;
    arAct.push_back(newAct);

    newAct.nAct = ACT_LISTEN;
    newAct.strTarget = "准备好";
    newAct.nDuration = 5;
    arAct.push_back(newAct);

    newAct.nAct = ACT_SPEAK;
    newAct.strTarget = "好的，五，四，三，二，一";
    newAct.nDuration = 10;
    arAct.push_back(newAct);

    newAct.nAct = ACT_CAP_IMAGE;
    newAct.strTarget = "/home/robot/photos/new.png";
    // newAct.nDuration = 5;
    arAct.push_back(newAct);

    newAct.nAct = ACT_SPEAK;
    newAct.strTarget = "我拍好啦";
    newAct.nDuration = 5;
    arAct.push_back(newAct);
}