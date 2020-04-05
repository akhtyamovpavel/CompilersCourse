#include "SubstractExpression.h"

SubstractExpression::SubstractExpression(Expression *e1, Expression *e2): first(e1), second(e2) {}

void SubstractExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}