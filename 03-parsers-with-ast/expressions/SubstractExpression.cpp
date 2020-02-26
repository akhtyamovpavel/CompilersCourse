#include "SubstractExpression.h"

SubstractExpression::SubstractExpression(Expression *e1, Expression *e2): first(e1), second(e2) {}

int SubstractExpression::eval() const {
    return first->eval() - second->eval();
}