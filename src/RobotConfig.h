#pragma once

class RobotConfig {
public:
    constexpr static const float MAX_ACCELERATION = 0.5f; // максимальное ускорение
    constexpr static const float MAX_DECELERATION = 0.8f; // максимальное замедление
    constexpr static const float MAX_SPEED = 2.0f; // максимальная скорость
    constexpr static const int WHEEL_STEP_DELAY = 1000; // задержка между расчётами
};