//
// Created by akhtyamovpavel on 3/11/21.
//

#include <symbols/StVariable.h>
#include <symbols/StFunction.h>
#include "SymbolTableVisitor.h"
#include "elements.h"
void SymbolTableVisitor::Visit(NumberExpression *expression) {

}

void SymbolTableVisitor::Visit(AddExpression *expression) {

}
void SymbolTableVisitor::Visit(SubstractExpression *expression) {

}
void SymbolTableVisitor::Visit(MulExpression *expression) {

}
void SymbolTableVisitor::Visit(DivExpression *expression) {

}
void SymbolTableVisitor::Visit(IdentExpression *expression) {

}
void SymbolTableVisitor::Visit(Assignment *assignment) {

}
void SymbolTableVisitor::Visit(VarDecl *var_decl) {
  GetScope()->elements[var_decl->variable_] = new StVariable(var_decl->variable_);
}

void SymbolTableVisitor::Visit(PrintStatement *statement) {

}
void SymbolTableVisitor::Visit(StatementList *assignment_list) {
  for (auto* statement: assignment_list->statements_) {
    statement->Accept(this);
  }
}
void SymbolTableVisitor::Visit(ScopeAssignmentList *list) {

}
void SymbolTableVisitor::Visit(Program *program) {
  program->statement_list_->Accept(this);
  program->function_list_->Accept(this);
}

void SymbolTableVisitor::Visit(ParamList *param_list) {

}
void SymbolTableVisitor::Visit(Function *function) {

}
void SymbolTableVisitor::Visit(FunctionCallExpression *statement) {

}
void SymbolTableVisitor::Visit(FunctionList *function_list) {
  BaseScope* parent_scope = GetScope();
  for (auto* function: function_list->functions_) {
    BaseScope* new_scope = Accept(function);
    parent_scope->elements[function->name_] = new StFunction(function);
    new_scope->parent_ = parent_scope;
  }
  SetValue(parent_scope);
}

void SymbolTableVisitor::Visit(ParamValueList *value_list) {

}
void SymbolTableVisitor::Visit(ReturnStatement *return_statement) {

}

BaseScope *SymbolTableVisitor::GetScope() {
  if (tos_value_ == nullptr) {
    tos_value_ = new BaseScope();
  }
  return tos_value_;
}
