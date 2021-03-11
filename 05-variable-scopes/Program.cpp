#include "Program.h"

Program::Program(
    StatementList* assignments,
    Expression* expression
): assignments_(assignments), expression_(expression) {}