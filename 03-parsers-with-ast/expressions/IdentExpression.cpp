#include "IdentExpression.h"

IdentExpression::IdentExpression(const std::string& ident): ident_(ident) {}

int IdentExpression::eval() const {
    return 0;
}