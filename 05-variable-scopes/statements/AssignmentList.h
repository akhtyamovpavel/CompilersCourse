#pragma once

#include "statements/Statement.h"
#include "base_elements/BaseElement.h"
#include <vector>

class AssignmentList : public BaseElement {
 public:
    void AddStatement(Statement* assignment);
    void Accept(Visitor* visitor);

    std::vector<Statement*> statements_;
};