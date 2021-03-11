#pragma once

#include "assignments/Assignment.h"

#include <vector>

class StatementList {
 public:
    void AddAssignment(Assignment* assignment);
 private:
    std::vector<Assignment*> assignments_;
};