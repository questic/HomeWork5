#pragma once
#include "Task.h"
#include <memory>

class MovableRobotPart {
public:
    virtual void Move() = 0;
    virtual void Stop() = 0;
};
