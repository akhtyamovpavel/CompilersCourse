#include "Program.h"

Program::Program(
    StatementList* assignments,
    Expression* expression
): assignments_(assignments), expression_(expression) {}


int Program::eval(Driver& driver) {
  return expression_->eval(driver);
}

