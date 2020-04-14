#include "ScopeAssignmentList.h"


ScopeAssignmentList::ScopeAssignmentList(AssignmentList *list):
    statement_list(list) {}

void ScopeAssignmentList::Accept(Visitor* visitor) {
    visitor->Visit(this);
}