#include "AddExpression.h"

AddExpression::AddExpression(Expression *e1, Expression *e2): first(e1), second(e2) {}

int AddExpression::eval(const Driver& driver) const {
    return first->eval(driver) + second->eval(driver);
}