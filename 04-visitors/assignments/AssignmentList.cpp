#include "AssignmentList.h"


void AssignmentList::AddAssignment(Statement* assignment) {
    assignments_.push_back(assignment);
}

void AssignmentList::Accept(Visitor* visitor) {
    visitor->Visit(this);
}