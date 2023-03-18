#include "Program.h"

Program::Program(
    FunctionList* function_list,
    StatementList* statement_list
): function_list_(function_list), statement_list_(statement_list) {}

void Program::Accept(Visitor* visitor) {
    visitor->Visit(this);
}