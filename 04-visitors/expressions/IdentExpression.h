#pragma once
#include "Expression.h"

#include <string>

class IdentExpression: public Expression {
 public:
    IdentExpression(const std::string& ident);
    int eval() const override;
    void Accept(Visitor* visitor) override;

    std::string ident_;
};