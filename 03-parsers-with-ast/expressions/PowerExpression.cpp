#include "PowerExpression.h"

PowerExpression::PowerExpression(
    Expression* expr1, Expression* expr2
    ): first(expr1), second(expr2) {}

int PowerExpression::eval(const Driver& driver) const {
    int power = second->eval(driver);
    int base = first->eval(driver);

    int result = 1;
    for (int count = 0; count < power; ++count) {
        result *= base;
    }

    return result;
}