#pragma once
#include "Chassis.h"
#include <memory>
#include <string>

class RobotSimulation {
private:
    std::shared_ptr<Chassis> m_chassis = std::make_shared<Chassis>();
    float m_currentX;
    float m_currentY;

public:
    RobotSimulation(const std::string& configFileName);
    RobotSimulation(int numberOfWheels);
    void LoadConfig(const std::string& configFileName);
    void StartSimulation();
    void StopSimulation();
    void MoveTo(float x, float y);
    void Stop();
};
