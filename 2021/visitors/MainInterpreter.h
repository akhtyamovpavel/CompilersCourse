//
// Created by akhtyamovpavel on 3/11/21.
//
#include <include/driver.hh>
#include "TemplateVisitor.h"

#pragma once

class MainInterpreter : public TemplateVisitor<int> {
 public:
  explicit MainInterpreter(Driver* driver);
  void Visit(NumberExpression *expression) override;
  void Visit(AddExpression *expression) override;
  void Visit(SubstractExpression *expression) override;
  void Visit(MulExpression *expression) override;
  void Visit(DivExpression *expression) override;
  void Visit(IdentExpression *expression) override;
  void Visit(Assignment *assignment) override;
  void Visit(VarDecl *var_decl) override;
  void Visit(PrintStatement *statement) override;
  void Visit(StatementList *assignment_list) override;
  void Visit(ScopeAssignmentList *list) override;
  void Visit(Program *program) override;
  void Visit(ParamList *param_list) override;
  void Visit(Function *function) override;
  void Visit(FunctionCallExpression *statement) override;
  void Visit(FunctionList *function_list) override;
  void Visit(ParamValueList *value_list) override;
  void Visit(ReturnStatement *return_statement) override;
 private:
  Driver* driver_;

};


