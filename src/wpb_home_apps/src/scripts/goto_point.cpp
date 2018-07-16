#include "goto_point.h"
CGotoPoint::CGotoPoint(){

}

CGotoPoint::~CGotoPoint(){

}

void CGotoPoint::Queue(std_msgs::String &voice_cmd)
{
    stAct newAct;    
    newAct.nAct = ACT_GOTO;
    newAct.strTarget = voice_cmd.data;
    newAct.nDuration = 5;
    arAct.push_back(newAct);

    newAct.nAct = ACT_SPEAK;
    newAct.strTarget = "！这就是 "+ voice_cmd.data+" 现在我要回去了";
    newAct.nDuration = 5;
    arAct.push_back(newAct);

    newAct.nAct = ACT_GOTO;
    newAct.strTarget = "start";
    newAct.nDuration = 5;
    arAct.push_back(newAct);

}

void CGotoPoint::SQueue()
{
    stAct spAct;
    spAct.nAct = ACT_SPEAK;
    spAct.strTarget = "!我要出发了";
    spAct.nDuration = 5;
    arAct.push_back(spAct);
}    