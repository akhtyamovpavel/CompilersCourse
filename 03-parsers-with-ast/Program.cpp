#include "Program.h"
#include "../04-visitors/visitors/Visitor.h"

Program::Program(
    StatementList* assignments,
    Expression* expression
): assignments_(assignments), expression_(expression) {}

void Program::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
