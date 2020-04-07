#include "AddExpression.h"

AddExpression::AddExpression(Expression *e1, Expression *e2): first(e1), second(e2) {}


void AddExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}