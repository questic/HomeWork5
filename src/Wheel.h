#pragma once
#include "MovableRobotPart.h"

class Wheel: public MovableRobotPart{
private:
    bool m_isMoving = false;
    float m_currentSpeed = 0;
    void AccelerateToSpeed(float targetSpeed);
    void DecelerateToStop();
    void Delay(int milliseconds);

public:
    void Move() override;
    void Stop() override;
};
