#include "PrintVisitor.h"

#include "elements.h"

#include <iostream>

PrintVisitor::PrintVisitor(const std::string& filename) : stream_(filename) {
}

void PrintVisitor::Visit(NumberExpression* expression) {
    PrintTabs();
    stream_ << "NumExpression " << expression->value_ << std::endl;
}

void PrintVisitor::Visit(AddExpression* expression) {
    PrintTabs();
    stream_ << "AddExpression is:" << std::endl;

    ++num_tabs_;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(SubstractExpression* expression) {
    PrintTabs();

    stream_ << "SubExpression: " << std::endl;
    ++num_tabs_;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(MulExpression* expression) {
    PrintTabs();

    stream_ << "MulExpression: " << std::endl;
    ++num_tabs_;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(DivExpression* expression) {
    PrintTabs();
    stream_ << "DivExpression: " << std::endl;
    ++num_tabs_;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(IdentExpression* expression) {
    PrintTabs();

    stream_ << "IdentExpression: " << expression->ident_ << std::endl;
}

void PrintVisitor::Visit(Assignment* assignment) {
    PrintTabs();
    stream_ << "Assignment: " << assignment->variable_ << std::endl;
    ++num_tabs_;
    assignment->expression_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(VarDecl* var_decl) {
    PrintTabs();
    stream_ << "VarDecl: " << var_decl->variable_ << std::endl;
}

void PrintVisitor::Visit(PrintStatement* statement) {
    PrintTabs();
    stream_ << "PrintStatement: " << std::endl;
    ++num_tabs_;
    statement->expression_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(StatementList* assignment_list) {
    PrintTabs();
    stream_ << "StatementList: " << std::endl;

    ++num_tabs_;
    for (Statement* assignment : assignment_list->statements_) {
        assignment->Accept(this);
    }
    --num_tabs_;
}

void PrintVisitor::Visit(ScopeAssignmentList* list) {
    stream_ << "ScopeAssignmentList:" << std::endl;
    ++num_tabs_;

    list->statement_list->Accept(this);
    --num_tabs_;
}
void PrintVisitor::Visit(Program* program) {
    stream_ << "Program:" << std::endl;

    ++num_tabs_;

    program->assignments_->Accept(this);
    program->expression_->Accept(this);

    --num_tabs_;
}

void PrintVisitor::PrintTabs() {
    for (int i = 0; i < num_tabs_; ++i) {
        stream_ << '\t';
    }
}

PrintVisitor::~PrintVisitor() {
    stream_.close();
}