#pragma once
#include "Expression.h"

class NumberExpression: public Expression {
public:
    explicit NumberExpression(int value);
    int eval(const Driver& driver) const override;
private:
    int value_;
};