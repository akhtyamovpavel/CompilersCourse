#include "Assignment.h"

Assignment::Assignment(
    const std::string& variable,
    Expression* expression
) : variable_(variable), expression_(expression) {}


void Assignment::Accept(Visitor* visitor) {
    visitor->Visit(this);
}