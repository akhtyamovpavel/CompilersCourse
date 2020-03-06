#include "Interpreter.h"

#include "elements.h"

#include <iostream>


Interpreter::Interpreter() {
    variables_["one"] = 1;
    variables_["two"] = 2;
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
    tos_value_ = variables_[expression->ident_];
}

void Interpreter::Visit(Assignment* assignment) {
    variables_[assignment->variable_] = Accept(assignment->expression_);
}

void Interpreter::Visit(AssignmentList* assignment_list) {
    for (Assignment* assignment: assignment_list->assignments_) {
        assignment->Accept(this);
    }
}

void Interpreter::Visit(Program* program) {
    program->assignments_->Accept(this);
    program->expression_->Accept(this); // tos value is called
}

int Interpreter::GetResult(Program *program) {
    Visit(program);
    return tos_value_;
}