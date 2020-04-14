#include "SymbolTreeVisitor.h"

#include "elements.h"

#include <iostream>

#include "types/Integer.h"


SymbolTreeVisitor::SymbolTreeVisitor(): tree_(new ScopeLayer) {
    current_layer_ = tree_.root_;
}

void SymbolTreeVisitor::Visit(NumberExpression* expression) {
}

void SymbolTreeVisitor::Visit(AddExpression* expression) {
    expression->first->Accept(this);
    expression->second->Accept(this);
}

void SymbolTreeVisitor::Visit(SubstractExpression* expression) {
    expression->first->Accept(this);
    expression->second->Accept(this);
}

void SymbolTreeVisitor::Visit(MulExpression* expression) {
    expression->first->Accept(this);
    expression->second->Accept(this);
}

void SymbolTreeVisitor::Visit(DivExpression* expression) {
    expression->first->Accept(this);
    expression->second->Accept(this);
}

void SymbolTreeVisitor::Visit(IdentExpression* expression) {
    current_layer_->Get(Symbol(expression->ident_)); // check that element exists
}

void SymbolTreeVisitor::Visit(Assignment* assignment) {
    current_layer_->Get(assignment->variable_);

    assignment->expression_->Accept(this);
}

void SymbolTreeVisitor::Visit(PrintStatement* statement) {
    statement->expression_->Accept(this);
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
    program->function_list_->Accept(this);

}

ScopeLayerTree SymbolTreeVisitor::GetRoot() {
    return tree_;
}

void SymbolTreeVisitor::Visit(ParamList *param_list) {
  for (const std::string& param: param_list->params_) {
    current_layer_->DeclareVariable(Symbol(param));
  }
}

void SymbolTreeVisitor::Visit(Function *function) {
  current_layer_->DeclareFunction(Symbol(function->name_), function);

  auto new_layer = new ScopeLayer(current_layer_);

  current_layer_ = new_layer;

  function->param_list_->Accept(this);
  function->statements_->Accept(this);

  tree_.AddMapping(Symbol(function->name_), new_layer);

  current_layer_ = current_layer_->GetParent();

  functions_[Symbol(function->name_)] = function;

}

std::unordered_map<Symbol, Function *> SymbolTreeVisitor::GetFunctions() const {
  return functions_;
}

void SymbolTreeVisitor::Visit(FunctionCallExpression *statement) {
    // We don't check function name because function could be created after
    statement->param_list_->Accept(this);
}

void SymbolTreeVisitor::Visit(FunctionList *function_list) {
    for (auto* function : function_list->functions_) {
        function->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(ParamValueList *value_list) {
    for (Expression* value : value_list->params_) {
        value->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(ReturnStatement *return_statement) {
    return_statement->return_expression_->Accept(this);
}

void SymbolTreeVisitor::Visit(AndExpression *and_expression) {
  and_expression->first->Accept(this);
  and_expression->second->Accept(this);
}

void SymbolTreeVisitor::Visit(OrExpression *or_expression) {
  or_expression->first->Accept(this);
  or_expression->second->Accept(this);
}

void SymbolTreeVisitor::Visit(NotExpression *not_expression) {
  not_expression->expression_->Accept(this);
}

void SymbolTreeVisitor::Visit(IfStatement *if_statement) {
  if_statement->bool_expression_->Accept(this);
  auto true_layer = new ScopeLayer(current_layer_);
  current_layer_ = true_layer;

  if_statement->true_statement_->Accept(this);

  current_layer_ = current_layer_->GetParent();

  auto false_layer = new ScopeLayer(current_layer_);
  current_layer_ = false_layer;

  if_statement->false_statement_->Accept(this);

  current_layer_ = current_layer_->GetParent();
}

void SymbolTreeVisitor::Visit(GtExpression *gt_expression) {
  gt_expression->first->Accept(this);
  gt_expression->second->Accept(this);
}

void SymbolTreeVisitor::Visit(LtExpression *lt_expression) {
  lt_expression->first->Accept(this);
  lt_expression->second->Accept(this);
}
