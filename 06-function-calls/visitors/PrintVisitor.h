#pragma once

#include "../include/visitors/Visitor.h"

#include <fstream>
#include <string>

class PrintVisitor: public Visitor {
 public:
    explicit PrintVisitor(const std::string& filename);
    ~PrintVisitor();
    void Visit(NumberExpression* expression) override;
    void Visit(AddExpression* expression) override;
    void Visit(SubstractExpression* expression) override;
    void Visit(MulExpression* expression) override;
    void Visit(DivExpression* expression) override;
    void Visit(IdentExpression* expression) override;
    void Visit(PrintStatement* statement) override;
    void Visit(Assignment* assignment) override;
    void Visit(VarDecl* var_decl) override;
    void Visit(AssignmentList* assignment_list) override;
    void Visit(ScopeAssignmentList* list) override;
    void Visit(Program* program) override;
    void Visit(ParamList* param_list) override;
    void Visit(Function *function) override;
    void Visit(FunctionList *function_list) override;
    void Visit(FunctionCallExpression *statement) override;

    void Visit(ParamValueList *value_list) override;

    void Visit(ReturnStatement *return_statement) override;

private:

    void PrintTabs();
    std::ofstream stream_;
    int num_tabs_ = 0;

};
