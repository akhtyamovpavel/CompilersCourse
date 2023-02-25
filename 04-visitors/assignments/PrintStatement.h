#pragma once

#include "expressions/Expression.h"
#include "base_elements/BaseElement.h"

#include <string>

#include "Statement.h"

class PrintStatement: public Statement {
 public:
    PrintStatement(Expression* expression);
    void Accept(Visitor* visitor);

    Expression* expression_;
};