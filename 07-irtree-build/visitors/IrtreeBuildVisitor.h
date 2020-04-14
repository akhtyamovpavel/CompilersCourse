//
// Created by akhtyamovpavel on 4/8/20.
//


#pragma once

#include <include/visitors/Visitor.h>
#include <irtree/tree_wrapper/SubtreeWrapper.h>
#include <unordered_map>
#include <function-mechanisms/FrameTranslator.h>
#include <symbol_table/ScopeLayerTree.h>
#include "TemplateVisitor.h"

using IrtMapping = std::unordered_map<std::string, IRT::Statement*>;

class IrtreeBuildVisitor : public TemplateVisitor<IRT::SubtreeWrapper*> {
  public:
  explicit IrtreeBuildVisitor(ScopeLayerTree* layer_tree);
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
   void Visit(ScopeAssignmentList *list) override;
   void Visit(Program *program) override;
   void Visit(ParamList *param_list) override;
   void Visit(Function *function) override;
   void Visit(FunctionCallExpression *statement) override;
   void Visit(FunctionList *function_list) override;
   void Visit(ParamValueList *value_list) override;
   void Visit(ReturnStatement *return_statement) override;
   void Visit(AndExpression *and_expression) override;
   void Visit(OrExpression *or_expression) override;
   void Visit(NotExpression *not_expression) override;
   void Visit(IfStatement *if_statement) override;
   void Visit(GtExpression *gt_expression) override;
   void Visit(LtExpression *lt_expression) override;

   IrtMapping GetTrees();

 private:
  std::unordered_map<std::string, IRT::FrameTranslator*> frame_translator_;

  IRT::FrameTranslator *current_frame_;
  ScopeLayerTree* tree_;

  IrtMapping method_trees_;
};


