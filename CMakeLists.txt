cmake_minimum_required(VERSION 3.26)
project(HomeWork5)

set(CMAKE_CXX_STANDARD 17)

add_executable(HomeWork5 src/main.cpp
        src/Task.h
        src/MoveTask.cpp
        src/MoveTask.h
        src/StopTask.cpp
        src/StopTask.h
        src/MovableRobotPart.h
        src/Wheel.cpp
        src/Wheel.h
        src/RobotConfig.h
        src/Chassis.cpp
        src/Chassis.h
        src/RobotSimulation.cpp
        src/RobotSimulation.h
)
