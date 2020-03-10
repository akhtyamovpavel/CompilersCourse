#pragma once

#include "statements/AssignmentList.h"
#include "expressions/Expression.h"

class Program {
 public:
    Program(AssignmentList* assignments, Expression* expression);
    AssignmentList* assignments_;
    Expression* expression_;
};