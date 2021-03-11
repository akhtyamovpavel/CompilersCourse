#pragma once

#include "Statement.h"
#include "base_elements/BaseElement.h"
#include <vector>

class StatementList : public Statement {
 public:
    void AddStatement(Statement* assignment);
    void Accept(Visitor* visitor);

    std::vector<Statement*> statements_;
};