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
    virtual void Visit(VarDecl* var_decl) = 0;
    virtual void Visit(PrintStatement* statement) = 0;
    virtual void Visit(AssignmentList* assignment_list) = 0;
    virtual void Visit(ScopeAssignmentList* list) = 0;
    virtual void Visit(Program* program) = 0;
    virtual void Visit(ParamList* param_list) = 0;
    virtual void Visit(Function* function) = 0;
};
