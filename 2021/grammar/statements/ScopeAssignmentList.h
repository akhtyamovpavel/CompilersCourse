#pragma once

#include "Statement.h"
#include "StatementList.h"
#include "base_elements/BaseElement.h"
#include <vector>

class ScopeAssignmentList : public Statement {
 public:
    explicit ScopeAssignmentList(StatementList* assignment_list);
    void Accept(Visitor* visitor) override;
    StatementList* statement_list;
};