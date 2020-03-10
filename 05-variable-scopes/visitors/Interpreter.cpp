#include "Interpreter.h"

#include "elements.h"

#include <iostream>

#include "objects/Integer.h"


Interpreter::Interpreter() {
    table_.Put(table_.GetSymbol("one"), std::make_shared<Integer>(1));
    table_.Put(table_.GetSymbol("two"), std::make_shared<Integer>(2));

    std::cout << table_.Get(table_.GetSymbol("one"))->ToInt() << std::endl;
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
    tos_value_ = table_.Get(table_.GetSymbol(expression->ident_))->ToInt();
}

void Interpreter::Visit(Assignment* assignment) {
    int value = Accept(assignment->expression_);

    table_.Put(table_.GetSymbol(assignment->variable_), std::make_shared<Integer>(value));
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
    table_.GetSymbol(var_decl->variable_);
}

void Interpreter::Visit(ScopeAssignmentList* list) {
    table_.BeginScope();
    list->statement_list->Accept(this);
    table_.EndScope();
}

void Interpreter::Visit(Program* program) {
    program->assignments_->Accept(this);
    program->expression_->Accept(this); // tos value is called
}

int Interpreter::GetResult(Program *program) {
    Visit(program);
    return tos_value_;
}