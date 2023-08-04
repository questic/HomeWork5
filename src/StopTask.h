#pragma once
#include "Task.h"

class StopTask: public Task {
public:
    void Execute() override;
};
