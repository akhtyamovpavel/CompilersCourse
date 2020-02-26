#pragma once

#include "assignments/AssignmentList.h"
#include "expressions/Expression.h"

class Program {
 public:
    Program(AssignmentList* assignments, Expression* expression);
 private:
    AssignmentList* assignments_;
    Expression* expression_;
};