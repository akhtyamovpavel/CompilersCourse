#include "DivExpression.h"

DivExpression::DivExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}

void DivExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}