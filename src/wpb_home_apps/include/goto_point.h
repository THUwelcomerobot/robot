#ifndef GOTO_POINT_H
#define GOTO_POINT_H
#include "action_manager.h"
#include <std_msgs/String.h>

class CGotoPoint : public CActionManager
{
public:
	CGotoPoint();
	~CGotoPoint();
    void Queue(std_msgs::String &voice_cmd);
    void SQueue();
};

#endif //