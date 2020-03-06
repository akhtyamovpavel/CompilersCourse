#pragma once

#include "assignments/Assignment.h"
#include "base_elements/BaseElement.h"
#include <vector>

class AssignmentList : public BaseElement {
 public:
    void AddAssignment(Assignment* assignment);
    void Accept(Visitor* visitor);

    std::vector<Assignment*> assignments_;
};