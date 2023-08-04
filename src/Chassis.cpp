#include "Chassis.h"
#include <iostream>

void Chassis::AddPart(std::shared_ptr<MovableRobotPart> part) {
    m_parts.push_back(part);
}

void Chassis::Move() {
    for (auto part : m_parts) {
        part->Move();
    }
}

void Chassis::Stop() {
    for (auto part : m_parts) {
        part->Stop();
    }
}

void Chassis::ProcessTask(std::shared_ptr<Task> task) {
        task->Execute();
}
