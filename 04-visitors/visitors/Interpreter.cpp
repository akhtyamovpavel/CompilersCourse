#include "Interpreter.h"

#include "elements.h"

#include <iostream>

Interpreter::Interpreter() {
    variables_["one"] = 1;
    variables_["two"] = 2;
    is_tos_expression_ = false;
    tos_value_ = 0;
}

void Interpreter::Visit(NumberExpression* expression) {
    SetTosValue(expression->value_);
}

void Interpreter::Visit(AddExpression* expression) {
    int value = 0;
    expression->first->Accept(this);
    value += tos_value_;

    expression->second->Accept(this);
    
    value += tos_value_;
    SetTosValue(value);
}

void Interpreter::Visit(SubstractExpression* expression) {
    expression->first->Accept(this);
    int value = tos_value_;
    expression->second->Accept(this);
    value -= tos_value_;
    
    SetTosValue(value);
}

void Interpreter::Visit(MulExpression* expression) {
    expression->first->Accept(this);
    int value = tos_value_;
    expression->second->Accept(this);
    value *= tos_value_;
    
    SetTosValue(value);
}

void Interpreter::Visit(DivExpression* expression) {
    expression->first->Accept(this);
    int value = tos_value_;
    expression->second->Accept(this);
    value /= tos_value_;

    SetTosValue(value);
}

void Interpreter::Visit(IdentExpression* expression) {
    int value = variables_[expression->ident_];

    SetTosValue(value);
}

void Interpreter::Visit(Assignment* assignment) {
    assignment->expression_->Accept(this);
    variables_[assignment->variable_] = tos_value_;

    UnsetTosValue();
}

void Interpreter::Visit(AssignmentList* assignment_list) {
    for (Assignment* assignment: assignment_list->assignments_) {
        assignment->Accept(this);
    }
    UnsetTosValue();
}

void Interpreter::Visit(Program* program) {
    program->assignments_->Accept(this);
    
    program->expression_->Accept(this); // tos value is called
}


void Interpreter::SetTosValue(int value) {
    tos_value_ = value;
    is_tos_expression_ = true;
}

void Interpreter::UnsetTosValue() {
    tos_value_ = 0;
    is_tos_expression_ = false;
}

int Interpreter::GetResult(Program *program) {
    UnsetTosValue();
    Visit(program);
    return tos_value_;
}