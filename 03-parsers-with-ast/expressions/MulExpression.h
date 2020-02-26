#pragma once
#include "Expression.h"

class MulExpression: public Expression {
 public:
    MulExpression(Expression* e1, Expression* e2);
    int eval() const override;
 private:
    Expression* first;
    Expression* second;
};