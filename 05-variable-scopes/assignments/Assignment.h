#pragma once

#include "expressions/Expression.h"
#include "base_elements/BaseElement.h"

#include <string>

class Assignment: public BaseElement {
 public:
    Assignment(const std::string& variable, Expression* expression);
    void Accept(Visitor* visitor);

    std::string variable_;
    Expression* expression_;
};