#pragma once

#include "expressions/Expression.h"

#include <string>

class Assignment {
 public:
    Assignment(const std::string& variable, Expression* expression);
 private:
    std::string variable_;
    Expression* expression_;
};