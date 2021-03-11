#pragma once

#include "assignments/AssignmentList.h"
#include "expressions/Expression.h"

class Program {
 public:
    Program(StatementList* assignments, Expression* expression);
 private:
    StatementList* assignments_;
    Expression* expression_;
};