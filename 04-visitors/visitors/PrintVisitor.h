#pragma once

#include "Visitor.h"

#include <fstream>
#include <string>

class PrintVisitor: public Visitor {
 public:
    PrintVisitor(const std::string& filename);
    ~PrintVisitor();
    void Visit(NumberExpression* expression) override;
    void Visit(AddExpression* expression) override;
    void Visit(SubstractExpression* expression) override;
    void Visit(MulExpression* expression) override;
    void Visit(DivExpression* expression) override;
    void Visit(IdentExpression* expression) override;
    void Visit(Assignment* assignment) override;
    void Visit(AssignmentList* assignment_list) override;
    void Visit(Program* program) override;
 private:

    void PrintTabs();
    std::ofstream stream_;
    int num_tabs_ = 0;

};
