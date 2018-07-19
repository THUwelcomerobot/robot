#include "add_point.h"
CAddPoint::CAddPoint(){

}
CAddPoint::~CAddPoint(){

}
void CAddPoint::Queue(){
    stAct newAct;
    newAct.nAct = ACT_ADD_WAYPOINT;
    newAct.strTarget = "start";
    newAct.nDuration = 3;
    arAct.push_back(newAct);

    newAct.nAct = ACT_SPEAK;
    newAct.strTarget = "！开始跟随定点，请你站到我前面让我跟着你，好吗";
    newAct.nDuration = 5;
    arAct.push_back(newAct);
    
    newAct.nAct = ACT_LISTEN;
    newAct.strTarget = "好的";
    newAct.nDuration = 5;
    arAct.push_back(newAct);


    newAct.nAct = ACT_SPEAK;
    newAct.strTarget = "！好的，开始跟随了";
    newAct.nDuration = 5;
    arAct.push_back(newAct);
    
    newAct.nAct = ACT_FOLLOW;
    newAct.fFollowDist = 0.5;
    arAct.push_back(newAct);

    newAct.nAct = ACT_LISTEN;
    newAct.strTarget = "办公室";
    newAct.nDuration = 5;
    arAct.push_back(newAct);

    newAct.nAct = ACT_ADD_WAYPOINT;
    newAct.strTarget = "office";
    newAct.nDuration = 5;
    arAct.push_back(newAct);

    newAct.nAct = ACT_SPEAK;
    newAct.strTarget = "我知道老师办公室在这里了";
    newAct.nDuration = 5;
    arAct.push_back(newAct);

    newAct.nAct = ACT_LISTEN;
    newAct.strTarget = "教室";
    newAct.nDuration = 5;
    arAct.push_back(newAct);

    newAct.nAct = ACT_ADD_WAYPOINT;
    newAct.strTarget = "classroom";
    newAct.nDuration = 5;
    arAct.push_back(newAct);

    newAct.nAct = ACT_SPEAK;
    newAct.strTarget = "我知道教室在这里了。这里面个个都是人才，说话又好听。";
    newAct.nDuration = 15;
    arAct.push_back(newAct);

    newAct.nAct = ACT_LISTEN;
    newAct.strTarget = "完毕";
    newAct.nDuration = 5;
    arAct.push_back(newAct);


    newAct.nAct = ACT_SPEAK;
    newAct.strTarget = "好的，我回去了";
    newAct.nDuration = 5;
    arAct.push_back(newAct);

    newAct.nAct = ACT_GOTO;
    newAct.strTarget = "start";
    newAct.nDuration = 5;
    arAct.push_back(newAct);


    newAct.nAct = ACT_SPEAK;
    newAct.strTarget = "任务完成";
    newAct.nDuration = 5;
    arAct.push_back(newAct);
    
}