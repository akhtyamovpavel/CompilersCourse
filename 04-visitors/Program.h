#pragma once

#include "assignments/AssignmentList.h"
#include "expressions/Expression.h"

class Program: BaseElement {
 public:
    Program(AssignmentList* assignments, Expression* expression);
    AssignmentList* assignments_;
    Expression* expression_;

    void Accept(Visitor* visitor) override;
};