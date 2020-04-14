#include "MulExpression.h"

MulExpression::MulExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}

void MulExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}