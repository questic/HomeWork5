#pragma once
#include "MovableRobotPart.h"
#include "Task.h"
#include <vector>
#include <memory>

class Chassis {
private:
    std::vector<std::shared_ptr<MovableRobotPart>> m_parts{};

public:
    void AddPart(std::shared_ptr<MovableRobotPart> part);
    void Move();
    void Stop();
    void ProcessTask(std::shared_ptr<Task> task);
};
