#include "ScopeAssignmentList.h"


ScopeAssignmentList::ScopeAssignmentList(StatementList *list):
    statement_list(list) {}

void ScopeAssignmentList::Accept(Visitor* visitor) {
    visitor->Visit(this);
}