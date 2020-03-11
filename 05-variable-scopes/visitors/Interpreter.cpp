#include "Interpreter.h"

#include "elements.h"

#include <iostream>

#include "objects/Integer.h"


Interpreter::Interpreter(): tree_(std::make_shared<ScopeLayer>()) {

    tree_.root_->DeclareVariable(Symbol("one"));
    tree_.root_->DeclareVariable(Symbol("two"));

    tree_.root_->Put(Symbol("one"), std::make_shared<Integer>(1));
    tree_.root_->Put(Symbol("two"), std::make_shared<Integer>(2));

    current_layer_ = tree_.root_;

    // table_.CreateVariable(Symbol("one"));
    // table_.CreateVariable(Symbol("two"));
    // table_.Put(Symbol("one"), std::make_shared<Integer>(1));
    // table_.Put(Symbol("two"), std::make_shared<Integer>(2));

    // std::cout << table_.Get(Symbol("one"))->ToInt() << std::endl;
    tos_value_ = 0;
}

void Interpreter::Visit(NumberExpression* expression) {
    tos_value_ = expression->value_;
}

void Interpreter::Visit(AddExpression* expression) {
    tos_value_ = Accept(expression->first) + Accept(expression->second);
}

void Interpreter::Visit(SubstractExpression* expression) {
    tos_value_ = Accept(expression->first) - Accept(expression->second);
}

void Interpreter::Visit(MulExpression* expression) {
    tos_value_ = Accept(expression->first) * Accept(expression->second);
}

void Interpreter::Visit(DivExpression* expression) {
    tos_value_ = Accept(expression->first) / Accept(expression->second);
}

void Interpreter::Visit(IdentExpression* expression) {
    // tos_value_ = table_.Get(Symbol(expression->ident_))->ToInt();
    tos_value_ = current_layer_->Get(Symbol(expression->ident_))->ToInt();
}

void Interpreter::Visit(Assignment* assignment) {
    int value = Accept(assignment->expression_);

    // table_.Put(Symbol(assignment->variable_), std::make_shared<Integer>(value));
    
    current_layer_->Put(Symbol(assignment->variable_), std::make_shared<Integer>(value));
}

void Interpreter::Visit(PrintStatement* statement) {
    int value = Accept(statement->expression_);

    std::cout << value << std::endl;
}

void Interpreter::Visit(AssignmentList* assignment_list) {
    for (Statement* assignment: assignment_list->statements_) {
        assignment->Accept(this);
    }
}

void Interpreter::Visit(VarDecl* var_decl) {
    // table_.CreateVariable(var_decl->variable_);

    std::cout << "Declaring var" << var_decl->variable_ << std::endl;
    current_layer_->DeclareVariable(Symbol(var_decl->variable_));
}

void Interpreter::Visit(ScopeAssignmentList* list) {
    auto new_layer = std::make_shared<ScopeLayer>(current_layer_);
    new_layer->AttachParent();

    current_layer_ = new_layer;
    list->statement_list->Accept(this);

    current_layer_ = current_layer_->GetParent();
}

void Interpreter::Visit(Program* program) {
    program->assignments_->Accept(this);
    program->expression_->Accept(this); // tos value is called
}

int Interpreter::GetResult(Program *program) {
    Visit(program);
    return tos_value_;
}