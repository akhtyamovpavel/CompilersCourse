#include "IdentExpression.h"

IdentExpression::IdentExpression(const std::string& ident): ident_(ident) {}

int IdentExpression::eval() const {
    return 0;
}

void IdentExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}