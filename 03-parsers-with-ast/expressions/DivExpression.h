#pragma once
#include "Expression.h"

class DivExpression: public Expression {
 public:
    DivExpression(Expression* e1, Expression* e2);
    int eval() const override;
 private:
    Expression* first;
    Expression* second;
};