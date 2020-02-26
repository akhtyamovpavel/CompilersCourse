#pragma once
#include "Expression.h"

#include <string>

class IdentExpression: public Expression {
 public:
    IdentExpression(const std::string& ident);
    int eval() const override;
 private:
    std::string ident_;
};