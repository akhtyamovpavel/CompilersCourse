#pragma once

#include "assignments/Statement.h"
#include "base_elements/BaseElement.h"
#include <vector>

class AssignmentList : public BaseElement {
 public:
    void AddAssignment(Statement* statement);
    void Accept(Visitor* visitor);

    std::vector<Statement*> assignments_;
};