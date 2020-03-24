#include "NumberExpression.h"

NumberExpression::NumberExpression(int value) {
    value_ = value;
}

int NumberExpression::eval() const {
    return value_;
}

void NumberExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}