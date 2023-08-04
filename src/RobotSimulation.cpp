#include "RobotSimulation.h"
#include "MoveTask.h"
#include "StopTask.h"
#include "Wheel.h"
#include <fstream>
#include <iostream>

RobotSimulation::RobotSimulation(const std::string &configFileName):m_currentX(0.0f), m_currentY(0.0f) {
    LoadConfig(configFileName);
}

RobotSimulation::RobotSimulation(int numberOfWheels):m_currentX(0.0f), m_currentY(0.0f) {
    for (int i = 0; i < numberOfWheels; i++) {
        std::shared_ptr<Wheel> wheel = std::make_shared<Wheel>();
        m_chassis->AddPart(wheel);
    }
}

void RobotSimulation::LoadConfig(const std::string &configFileName) {
    std::ifstream configFile(configFileName);

    if (configFile.is_open()) {
        std::string line;

        while (std::getline(configFile, line)) {
            if (line == "wheel") {
                std::shared_ptr<Wheel> wheel = std::make_shared<Wheel>();
                m_chassis->AddPart(wheel);
            }
        }

        configFile.close();
    } else {
        std::cout << "Error opening file: " << configFileName << std::endl;
    }
}

void RobotSimulation::StartSimulation() {
    std::cout << "Robot control simulation started." << std::endl;
}

void RobotSimulation::StopSimulation() {
    std::cout << "The robot control simulation is complete." << std::endl;
}

void RobotSimulation::MoveTo(float x, float y) {
    std::shared_ptr<Task> moveTask = std::make_shared<MoveTask>(x, y);
    m_chassis->ProcessTask(moveTask);
    m_chassis->Move();
    m_currentX = x;
    m_currentY = y;
    std::cout << "The robot in point (" << m_currentX << ", " << m_currentY << ")" << std::endl;
    Stop();
}

void RobotSimulation::Stop() {
    m_chassis->Stop();
    std::shared_ptr<Task> stopTask = std::make_shared<StopTask>();
    m_chassis->ProcessTask(stopTask);
}
