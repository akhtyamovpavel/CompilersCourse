#pragma once

#include "expressions/Expression.h"
#include "Statement.h"

#include <string>

class PrintStatement: public Statement {
 public:
    PrintStatement(Expression* expression);
    void Accept(Visitor* visitor);

    Expression* expression_;
};