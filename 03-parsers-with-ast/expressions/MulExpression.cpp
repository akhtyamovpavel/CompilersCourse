#include "MulExpression.h"

MulExpression::MulExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}

int MulExpression::eval(const Driver& driver) const {
    return first->eval(driver) * second->eval(driver);
}