#pragma once
#include "Expression.h"

class SubstractExpression: public Expression {
 public:
    SubstractExpression(Expression* e1, Expression* e2);
    int eval(const Driver& driver) const override;
 private:
    Expression* first;
    Expression* second;
};