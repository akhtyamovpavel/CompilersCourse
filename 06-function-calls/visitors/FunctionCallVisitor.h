//
// Created by Pavel Akhtyamov on 25.03.2020.
//

#pragma once

#include <symbol_table/ScopeLayer.h>
#include <stack>
#include <function-mechanisms/Frame.h>
#include <function-mechanisms/FunctionTable.h>
#include <symbol_table/ScopeLayerTree.h>
#include "TemplateVisitor.h"

class FunctionCallVisitor: public TemplateVisitor<int> {
 public:
  FunctionCallVisitor(
          ScopeLayer* function_scope, std::shared_ptr<FunctionType> function);

  void SetTree(ScopeLayerTree* tree);

  void SetParams(const std::vector<int>& params);
  void Visit(NumberExpression *expression) override;
  void Visit(AddExpression *expression) override;
  void Visit(SubstractExpression *expression) override;
  void Visit(MulExpression *expression) override;
  void Visit(DivExpression *expression) override;
  void Visit(IdentExpression *expression) override;
  void Visit(Assignment *assignment) override;
  void Visit(VarDecl *var_decl) override;
  void Visit(PrintStatement *statement) override;
  void Visit(AssignmentList *assignment_list) override;
  void Visit(FunctionCallExpression *statement) override;
  void Visit(ScopeAssignmentList *list) override;
  void Visit(Program *program) override;
  void Visit(ParamList *param_list) override;
  void Visit(Function *function) override;
  void Visit(FunctionList *function_list) override;

    void Visit(ParamValueList *value_list) override;

    void Visit(ReturnStatement *return_statement) override;

  Frame& GetFrame();

private:
  ScopeLayer* root_layer;
  ScopeLayer* current_layer_;
  std::stack<int> offsets_;
  Frame frame;
  FunctionTable table_;
  ScopeLayerTree* tree_;
  bool returned_ = false;

};



