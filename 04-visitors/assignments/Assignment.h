#pragma once

#include "expressions/Expression.h"
#include "Statement.h"

#include <string>

class Assignment: public Statement {
 public:
    Assignment(const std::string& variable, Expression* expression);
    void Accept(Visitor* visitor);

    std::string variable_;
    Expression* expression_;
};