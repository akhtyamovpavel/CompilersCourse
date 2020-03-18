#include "PrintVisitor.h"

#include "elements.h"

#include <iostream>

SymbolTreeVisitor::SymbolTreeVisitor(const std::string& filename) : stream_(filename) {
}

void SymbolTreeVisitor::Visit(NumberExpression* expression) {
    PrintTabs();
    stream_ << "NumExpression " << expression->value_ << std::endl;
}

void SymbolTreeVisitor::Visit(AddExpression* expression) {
    PrintTabs();
    stream_ << "AddExpression is:" << std::endl;

    ++num_tabs_;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(SubstractExpression* expression) {
    PrintTabs();

    stream_ << "SubExpression: " << std::endl;
    ++num_tabs_;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(MulExpression* expression) {
    PrintTabs();

    stream_ << "MulExpression: " << std::endl;
    ++num_tabs_;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(DivExpression* expression) {
    PrintTabs();
    stream_ << "DivExpression: " << std::endl;
    ++num_tabs_;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(IdentExpression* expression) {
    PrintTabs();

    stream_ << "IdentExpression: " << expression->ident_ << std::endl;
}

void SymbolTreeVisitor::Visit(Assignment* assignment) {
    PrintTabs();
    stream_ << "Assignment: " << assignment->variable_ << std::endl;
    ++num_tabs_;
    assignment->expression_->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(AssignmentList* assignment_list) {
    PrintTabs();
    stream_ << "AssignmentList: " << std::endl;

    ++num_tabs_;
    for (Assignment* assignment : assignment_list->assignments_) {
        assignment->Accept(this);
    }
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(Program* program) {
    stream_ << "Program:" << std::endl;

    ++num_tabs_;

    program->assignments_->Accept(this);
    program->expression_->Accept(this);

    --num_tabs_;
}

void SymbolTreeVisitor::PrintTabs() {
    for (int i = 0; i < num_tabs_; ++i) {
        stream_ << '\t';
    }
}

SymbolTreeVisitor::~SymbolTreeVisitor() {
    stream_.close();
}