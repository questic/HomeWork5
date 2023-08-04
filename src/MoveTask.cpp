#include "MoveTask.h"
#include <iostream>

MoveTask::MoveTask(float x, float y): m_targetX(x), m_targetY(y) {

}

void MoveTask::Execute() {
    std::cout << "The robot goes to the point (" << m_targetX << ", " << m_targetY << ")" << std::endl;
}
