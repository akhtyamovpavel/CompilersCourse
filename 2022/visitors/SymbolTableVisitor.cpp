//
// Created by akhtyamovpavel on 3/11/21.
//

#include <iostream>
#include "SymbolTableVisitor.h"
#include "elements.h"

#include <symbols/VariableSymbol.h>
#include <symbols/Function.h>


void SymbolTableVisitor::Visit(NumberExpression *expression) {

}

void SymbolTableVisitor::Visit(AddExpression *expression) {
    Accept(expression->first);
    Accept(expression->second);
}

void SymbolTableVisitor::Visit(SubstractExpression *expression) {
    Accept(expression->first);
    Accept(expression->second);
}

void SymbolTableVisitor::Visit(MulExpression *expression) {
    Accept(expression->first);
    Accept(expression->second);
}

void SymbolTableVisitor::Visit(DivExpression *expression) {
    Accept(expression->first);
    Accept(expression->second);
}
void SymbolTableVisitor::Visit(IdentExpression *expression) {
  if (!current_scope->GetVariable(expression->ident_)) {
    throw std::runtime_error("Variable not declared");
  }
}

void SymbolTableVisitor::Visit(Assignment *assignment) {
  std::cout << "VISITED ASSIGNMENT" << std::endl;
  if (!current_scope->GetVariable(assignment->variable_)) {
    throw std::runtime_error("Variable not declared");
  }
  Accept(assignment->expression_);
}

void SymbolTableVisitor::Visit(VarDecl *var_decl) {
    std::cerr << "VAR DECL" << std::endl;
    if (current_scope->GetVariable(var_decl->variable_, true)) {
        throw std::runtime_error("Var already declared");
    }

    auto *symbol = new symbols::VariableSymbol();
    symbol->name = var_decl->variable_;
    current_scope->elements[var_decl->variable_] = symbol;

}

void SymbolTableVisitor::Visit(PrintStatement *statement) {
  Accept(statement->expression_);
}

void SymbolTableVisitor::Visit(StatementList *assignment_list) {
  for (auto* statement : assignment_list->statements_) {
      statement->Accept(this);
  }
}

void SymbolTableVisitor::Visit(ScopeAssignmentList *list) {
  auto *new_scope = new symbols::BaseScope(current_scope);

  current_scope->children_.push_back(new_scope);

  current_scope = new_scope;

  Accept(list->statement_list);

  current_scope = current_scope->parent_;
}

void SymbolTableVisitor::Visit(Program *program) {
  for (auto function: program->function_list_->functions_) {
    current_scope->named_children_[function->name_] = new symbols::BaseScope();
    auto function_symbol = new symbols::Function();
    current_scope->elements[function->name_] = function_symbol;
  }

  for (auto function: program->function_list_->functions_) {
    Accept(function);
  }
}

void SymbolTableVisitor::Visit(ParamList *param_list) {

}
void SymbolTableVisitor::Visit(Function *function) {
  std::cerr << "FUNCTION" << std::endl;
  function->statements_->Accept(this);
}


void SymbolTableVisitor::Visit(FunctionCallExpression *statement) {

}
void SymbolTableVisitor::Visit(FunctionList *function_list) {

}
void SymbolTableVisitor::Visit(ParamValueList *value_list) {

}
void SymbolTableVisitor::Visit(ReturnStatement *return_statement) {

}

SymbolTableVisitor::SymbolTableVisitor(Driver *driver): driver_(driver) {
    root = new symbols::BaseScope();
    auto *main_scope = new symbols::BaseScope(root);
    current_scope = main_scope;
    std::cerr << "CONSTRUCTOR CALLED" << std::endl;
}
