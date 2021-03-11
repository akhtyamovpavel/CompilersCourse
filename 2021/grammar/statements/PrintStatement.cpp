#include "PrintStatement.h"

PrintStatement::PrintStatement(
    Expression* expression
) : expression_(expression) {}


void PrintStatement::Accept(Visitor* visitor) {
    visitor->Visit(this);
}