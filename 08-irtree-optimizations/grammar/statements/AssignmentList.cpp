#include "AssignmentList.h"


void AssignmentList::AddStatement(Statement* assignment) {
    statements_.push_back(assignment);
}

void AssignmentList::Accept(Visitor* visitor) {
    visitor->Visit(this);
}