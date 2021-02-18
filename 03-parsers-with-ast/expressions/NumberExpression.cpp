#include "NumberExpression.h"

NumberExpression::NumberExpression(int value) {
    value_ = value;
}

int NumberExpression::eval(const Driver& driver) const {
    return value_;
}