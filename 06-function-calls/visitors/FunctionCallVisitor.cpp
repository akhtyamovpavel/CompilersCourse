//
// Created by Pavel Akhtyamov on 25.03.2020.
//

#include <types/Integer.h>
#include <iostream>
#include "FunctionCallVisitor.h"

#include "elements.h"

void FunctionCallVisitor::Visit(NumberExpression *expression) {
  tos_value_ = expression->value_;
}

void FunctionCallVisitor::Visit(AddExpression *expression) {
  tos_value_ = Accept(expression->first) + Accept(expression->second);
}

void FunctionCallVisitor::Visit(SubstractExpression *expression) {
  tos_value_ = Accept(expression->first) - Accept(expression->second);
}

void FunctionCallVisitor::Visit(MulExpression *expression) {
  tos_value_ = Accept(expression->first) * Accept(expression->second);
}

void FunctionCallVisitor::Visit(DivExpression *expression) {
  tos_value_ = Accept(expression->first) / Accept(expression->second);
}

void FunctionCallVisitor::Visit(IdentExpression *expression) {
  tos_value_ = current_layer_->Get(Symbol(expression->ident_))->ToInt();
}

void FunctionCallVisitor::Visit(Assignment *assignment) {
  int value = Accept(assignment->expression_);

  current_layer_->Put(Symbol(assignment->variable_), std::make_shared<Integer>(value));
}

void FunctionCallVisitor::Visit(VarDecl *var_decl) {
  size_t index = frame.AllocVariable();

}

void FunctionCallVisitor::Visit(PrintStatement *statement) {
  int value = Accept(statement->expression_);

  std::cout << value << std::endl;
}

void FunctionCallVisitor::Visit(AssignmentList *assignment_list) {
  for (Statement* assignment: assignment_list->statements_) {
    assignment->Accept(this);
  }
}

void FunctionCallVisitor::Visit(ScopeAssignmentList *list) {
  std::cout << "Going inside" << std::endl;

  current_layer_ = current_layer_->GetChild(offsets_.top());

  offsets_.push(0);
  frame.AllocScope();
  list->statement_list->Accept(this);

  offsets_.pop();
  size_t index = offsets_.top();

  offsets_.pop();
  offsets_.push(index + 1);

  current_layer_ = current_layer_->GetParent();
  frame.DeallocScope();
}

void FunctionCallVisitor::Visit(Program *program) {

}

void FunctionCallVisitor::Visit(ParamList *param_list) {

}

void FunctionCallVisitor::Visit(Function *function) {
  function->statements_->Accept(this);
}

FunctionCallVisitor::FunctionCallVisitor(
    ScopeLayer* function_scope, std::shared_ptr<FunctionType> function
    ) : root_layer(function_scope), frame(function) {
  current_layer_ = root_layer;
  current_layer_->Put(Symbol("one"), std::make_shared<Integer>(1));
  current_layer_->Put(Symbol("two"), std::make_shared<Integer>(2));
  offsets_.push(0);
  tos_value_ = 0;
}

void FunctionCallVisitor::SetParams(const std::vector<int> &params) {
  frame.SetParams(params);
}
