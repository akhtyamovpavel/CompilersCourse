#pragma once

#include "forward_decl.h"

class Visitor {
 public:
    virtual void Visit(NumberExpression* expression) = 0;
    virtual void Visit(AddExpression* expression) = 0;
    virtual void Visit(SubstractExpression* expression) = 0;
    virtual void Visit(MulExpression* expression) = 0;
    virtual void Visit(DivExpression* expression) = 0;
    virtual void Visit(IdentExpression* expression) = 0;
    virtual void Visit(Assignment* assignment) = 0;
    virtual void Visit(AssignmentList* assignment_list) = 0;
    virtual void Visit(Program* program) = 0;
};
