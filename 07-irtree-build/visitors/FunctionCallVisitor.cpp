//
// Created by Pavel Akhtyamov on 25.03.2020.
//

#include <types/Integer.h>
#include <iostream>
#include <function-mechanisms/FunctionStorage.h>
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
  int index = table_.Get(Symbol(expression->ident_));
  tos_value_ = frame.Get(index);
}

void FunctionCallVisitor::Visit(Assignment *assignment) {
  int value = Accept(assignment->expression_);

  int index = table_.Get(Symbol(assignment->variable_));
  frame.Set(index, value);
}

void FunctionCallVisitor::Visit(VarDecl *var_decl) {
  size_t index = frame.AllocVariable();
  table_.CreateVariable(Symbol(var_decl->variable_));
  table_.Put(Symbol(var_decl->variable_), index);

}

void FunctionCallVisitor::Visit(PrintStatement *statement) {
  int value = Accept(statement->expression_);

  std::cout << value << std::endl;
}

void FunctionCallVisitor::Visit(AssignmentList *assignment_list) {
  for (Statement* assignment: assignment_list->statements_) {
      if (!returned_) {
          assignment->Accept(this);
      }
  }
}

void FunctionCallVisitor::Visit(ScopeAssignmentList *list) {
  std::cout << "Going inside" << std::endl;

  current_layer_ = current_layer_->GetChild(offsets_.top());

  offsets_.push(0);
  frame.AllocScope();
  table_.BeginScope();
  list->statement_list->Accept(this);

  offsets_.pop();
  size_t index = offsets_.top();

  offsets_.pop();
  offsets_.push(index + 1);

  current_layer_ = current_layer_->GetParent();
  frame.DeallocScope();
  table_.EndScope();
}

void FunctionCallVisitor::Visit(Program *program) {

}

void FunctionCallVisitor::Visit(ParamList *param_list) {
    int index = -1;
    for (auto param: param_list->params_) {
        table_.CreateVariable(Symbol(param));
        table_.Put(Symbol(param), index);
        --index;
    }
}

void FunctionCallVisitor::Visit(Function *function) {
    function->param_list_->Accept(this);
  function->statements_->Accept(this);
}

FunctionCallVisitor::FunctionCallVisitor(
    ScopeLayer* function_scope, std::shared_ptr<FunctionType> function
    ) : root_layer(function_scope), frame(function) {
  current_layer_ = root_layer;
  offsets_.push(0);
  tos_value_ = 0;
}

void FunctionCallVisitor::SetParams(const std::vector<int> &params) {
  frame.SetParams(params);
}

void FunctionCallVisitor::Visit(FunctionCallExpression *statement) {
  std::cerr << "Function called " << statement->name_ << std::endl;
  auto function_type = current_layer_->Get(statement->name_);

  std::shared_ptr<FunctionType> func_converted = std::dynamic_pointer_cast<FunctionType>(function_type);

  if (func_converted == nullptr) {
    throw std::runtime_error("Function not defined");
  }

  std::vector<int> params;

  for (auto param : statement->param_list_->params_) {
      params.push_back(Accept(param));
  }

  FunctionCallVisitor new_visitor(
      tree_->GetFunctionScopeByName(statement->name_),
      func_converted
  );
  new_visitor.SetParams(params);

  new_visitor.GetFrame().SetParentFrame(&frame);
  new_visitor.Visit(FunctionStorage::GetInstance().Get(Symbol(statement->name_)));


  tos_value_ = frame.GetReturnValue();
}

void FunctionCallVisitor::Visit(FunctionList *function_list) {

}

void FunctionCallVisitor::Visit(ParamValueList *value_list) {

}

void FunctionCallVisitor::Visit(ReturnStatement *return_statement) {
    if (frame.HasParent()) {
        frame.SetParentReturnValue(Accept(return_statement->return_expression_));
    }
    returned_ = true;
}

void FunctionCallVisitor::SetTree(ScopeLayerTree *tree) {
    tree_ = tree;

}

Frame &FunctionCallVisitor::GetFrame() {
    return frame;
}
