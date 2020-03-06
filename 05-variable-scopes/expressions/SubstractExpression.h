#pragma once
#include "Expression.h"

class SubstractExpression: public Expression {
 public:
    SubstractExpression(Expression* e1, Expression* e2);
    int eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* first;
    Expression* second;
};