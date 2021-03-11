#include "AssignmentList.h"


void StatementList::AddAssignment(Assignment* assignment) {
    assignments_.push_back(assignment);
}