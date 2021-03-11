#include "Interpreter.h"

#include "elements.h"

#include <iostream>

#include "types/Integer.h"


Interpreter::Interpreter(ScopeLayerTree root): tree_(root) {

    current_layer_ = tree_.root_;
    current_layer_->Put(Symbol("one"), std::make_shared<Integer>(1));
    current_layer_->Put(Symbol("two"), std::make_shared<Integer>(2));
    offsets_.push(0);
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
    tos_value_ = current_layer_->Get(Symbol(expression->ident_))->ToInt();
}

void Interpreter::Visit(Assignment* assignment) {
    int value = Accept(assignment->expression_);
    
    current_layer_->Put(Symbol(assignment->variable_), std::make_shared<Integer>(value));
}

void Interpreter::Visit(PrintStatement* statement) {
    int value = Accept(statement->expression_);

    std::cout << value << std::endl;
}

void Interpreter::Visit(StatementList* assignment_list) {
    for (Statement* assignment: assignment_list->statements_) {
        assignment->Accept(this);
    }
}

void Interpreter::Visit(VarDecl* var_decl) {
    std::cout << "Var decl called" << std::endl;
}

void Interpreter::Visit(ScopeAssignmentList* list) {
    std::cout << "Going inside" << std::endl;

    current_layer_ = current_layer_->GetChild(offsets_.top());

    offsets_.push(0);
    list->statement_list->Accept(this);

    offsets_.pop();
    size_t index = offsets_.top();

    offsets_.pop();
    offsets_.push(index + 1);

    current_layer_ = current_layer_->GetParent();
}

void Interpreter::Visit(Program* program) {
    program->function_list_->Accept(this);
}

int Interpreter::GetResult(Program *program) {
    Visit(program);
    return tos_value_;
}

void Interpreter::Visit(ParamList *param_list) {

}

void Interpreter::Visit(Function *function) {

}

void Interpreter::Visit(FunctionCallExpression *statement) {

}

void Interpreter::Visit(FunctionList *function_list) {

}

void Interpreter::Visit(ParamValueList *value_list) {

}

void Interpreter::Visit(ReturnStatement *return_statement) {

}
