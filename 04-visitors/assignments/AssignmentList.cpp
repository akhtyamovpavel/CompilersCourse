#include "AssignmentList.h"


void StatementList::AddAssignment(Assignment* assignment) {
    assignments_.push_back(assignment);
}

void StatementList::Accept(Visitor* visitor) {
    visitor->Visit(this);
}