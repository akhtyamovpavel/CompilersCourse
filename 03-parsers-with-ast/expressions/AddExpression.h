#pragma once
#include "Expression.h"

class AddExpression: public Expression {
 public:
    AddExpression(Expression* e1, Expression* e2);
    int eval(const Driver& driver) const override;
 private:
    Expression* first;
    Expression* second;
};