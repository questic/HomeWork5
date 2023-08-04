#include "Wheel.h"
#include "RobotConfig.h"
#include <thread>
#include <iostream>

void Wheel::Delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void Wheel::AccelerateToSpeed(float targetSpeed) {
    while (m_currentSpeed < targetSpeed) {
        m_currentSpeed = std::min(m_currentSpeed + RobotConfig::MAX_ACCELERATION * RobotConfig::WHEEL_STEP_DELAY / 1000.0f, targetSpeed);
        std::cout << "Speed: " << m_currentSpeed << " m/s." << std::endl;
        Delay(RobotConfig::WHEEL_STEP_DELAY);
    }
}

void Wheel::DecelerateToStop() {
    while (m_currentSpeed > 0) {
        m_currentSpeed = std::max(m_currentSpeed - RobotConfig::MAX_DECELERATION * RobotConfig::WHEEL_STEP_DELAY / 1000.0f, 0.0f);
        std::cout << "Speed: " << m_currentSpeed << " m/s" <<std::endl;
        Delay(RobotConfig::WHEEL_STEP_DELAY);
    }
}

void Wheel::Move() {
    if (!m_isMoving) {
        m_isMoving = true;
        m_currentSpeed = 0.0f;
        AccelerateToSpeed(RobotConfig::MAX_SPEED);
        std::cout << "The wheel is spinning." << std::endl;
    }
}

void Wheel::Stop() {
    if (m_isMoving) {
        m_isMoving = false;
        DecelerateToStop();
        std::cout << "Wheel stopped." << std::endl;
    }
}

