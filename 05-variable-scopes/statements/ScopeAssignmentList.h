#pragma once

#include "statements/Statement.h"
#include "statements/AssignmentList.h"
#include "base_elements/BaseElement.h"
#include <vector>

class ScopeAssignmentList : public Statement {
 public:
    explicit ScopeAssignmentList(StatementList* assignment_list);
    void Accept(Visitor* visitor) override;
    StatementList* statement_list;
};