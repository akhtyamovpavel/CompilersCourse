#pragma once

#include "Statement.h"
#include "AssignmentList.h"
#include "base_elements/BaseElement.h"
#include <vector>

class ScopeAssignmentList : public Statement {
 public:
    explicit ScopeAssignmentList(AssignmentList* assignment_list);
    void Accept(Visitor* visitor) override;
    AssignmentList* statement_list;
};