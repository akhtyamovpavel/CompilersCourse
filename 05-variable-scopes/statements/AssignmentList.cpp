#include "AssignmentList.h"


void StatementList::AddStatement(Statement* assignment) {
    statements_.push_back(assignment);
}

void StatementList::Accept(Visitor* visitor) {
    visitor->Visit(this);
}