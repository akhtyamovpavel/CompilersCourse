#include "DivExpression.h"

DivExpression::DivExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}

int DivExpression::eval(const Driver& driver) const {
    return first->eval(driver) / second->eval(driver);
}