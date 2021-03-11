#pragma once
#include "Expression.h"

class AddExpression: public Expression {
 public:
    AddExpression(Expression* e1, Expression* e2);
    void Accept(Visitor* visitor) override;
    Expression* first;
    Expression* second;
};