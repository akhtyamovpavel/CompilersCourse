#pragma once
#include "Expression.h"

#include <string>

class Driver;

class IdentExpression: public Expression {
 public:
    IdentExpression(const std::string& ident);
    int eval(const Driver& driver) const override;
 private:
    std::string ident_;
};