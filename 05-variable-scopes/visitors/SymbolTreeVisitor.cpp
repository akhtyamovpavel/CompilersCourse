#include "SymbolTreeVisitor.h"

#include "elements.h"

#include <iostream>

#include "objects/Integer.h"


SymbolTreeVisitor::SymbolTreeVisitor(): tree_(new ScopeLayer) {

    tree_.root_->DeclareVariable(Symbol("one"));
    tree_.root_->DeclareVariable(Symbol("two"));

//    tree_.root_->Put(Symbol("one"), std::make_shared<Integer>(1));
//    tree_.root_->Put(Symbol("two"), std::make_shared<Integer>(2));

    current_layer_ = tree_.root_;

//    path_.push_back(tree_.root_);
}

void SymbolTreeVisitor::Visit(NumberExpression* expression) {
}

void SymbolTreeVisitor::Visit(AddExpression* expression) {
}

void SymbolTreeVisitor::Visit(SubstractExpression* expression) {
}

void SymbolTreeVisitor::Visit(MulExpression* expression) {
}

void SymbolTreeVisitor::Visit(DivExpression* expression) {
}

void SymbolTreeVisitor::Visit(IdentExpression* expression) {
}

void SymbolTreeVisitor::Visit(Assignment* assignment) {

}

void SymbolTreeVisitor::Visit(PrintStatement* statement) {
}

void SymbolTreeVisitor::Visit(AssignmentList* assignment_list) {
    for (Statement* assignment: assignment_list->statements_) {
        assignment->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(VarDecl* var_decl) {
    std::cout << "Declaring var " << var_decl->variable_ << std::endl;
    current_layer_->DeclareVariable(Symbol(var_decl->variable_));
}

void SymbolTreeVisitor::Visit(ScopeAssignmentList* list) {
    auto new_layer = new ScopeLayer(current_layer_);

    current_layer_ = new_layer;
    list->statement_list->Accept(this);
    current_layer_ = current_layer_->GetParent();
}

void SymbolTreeVisitor::Visit(Program* program) {
    program->assignments_->Accept(this);
    program->expression_->Accept(this); // tos value is called
}

ScopeLayer* SymbolTreeVisitor::GetRoot() {
    return current_layer_;
}