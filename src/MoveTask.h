#pragma  once
#include "Task.h"

class MoveTask: public Task {
private:
    float m_targetX;
    float m_targetY;

public:
    MoveTask(float x, float y);
    void Execute() override;
};
