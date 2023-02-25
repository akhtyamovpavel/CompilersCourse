#include "Program.h"

Program::Program(
    AssignmentList* assignments,
    Expression* expression
): assignments_(assignments), expression_(expression) {}


void Program::Accept(Visitor *v) {
    v->Visit(this);
}