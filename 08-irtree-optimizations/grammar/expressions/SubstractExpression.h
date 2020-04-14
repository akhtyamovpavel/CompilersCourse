#pragma once
#include "Expression.h"

class SubstractExpression: public Expression {
 public:
    SubstractExpression(Expression* e1, Expression* e2);
    void Accept(Visitor* visitor) override;

    Expression* first;
    Expression* second;
};