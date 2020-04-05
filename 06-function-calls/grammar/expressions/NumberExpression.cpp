#include "NumberExpression.h"

NumberExpression::NumberExpression(int value) {
    value_ = value;
}

void NumberExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}