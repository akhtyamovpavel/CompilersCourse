#pragma once
#include "Expression.h"

#include <string>

class IdentExpression: public Expression {
 public:
    IdentExpression(const std::string& ident);
    void Accept(Visitor* visitor) override;

    std::string ident_;
};