#pragma once

#include "assignments/AssignmentList.h"
#include "expressions/Expression.h"

class Program {
 public:
    Program(StatementList* assignments, Expression* expression);
    int eval(Driver& driver);
 private:
    StatementList* assignments_;
    Expression* expression_;
};