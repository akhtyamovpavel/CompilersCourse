//
// Created by akhtyamovpavel on 4/15/20.
//


#pragma once

#include "TemplateVisitor.h"
#include "VisitorStruct.h"
namespace IRT {
class DoubleCallEliminateVisitor: public TemplateVisitor<IrtStorage> {
 public:
  void Visit(ExpStatement *stmt) override;
  void Visit(ConstExpression *const_expression) override;
  void Visit(JumpConditionalStatement *jump_conditional_statement) override;
  void Visit(MoveStatement *move_statement) override;
  void Visit(SeqStatement *seq_statement) override;
  void Visit(LabelStatement *label_statement) override;
  void Visit(BinopExpression *binop_statement) override;
  void Visit(TempExpression *temp_exression) override;
  void Visit(MemExpression *mem_expression) override;
  void Visit(JumpStatement *jump_statement) override;
  void Visit(CallExpression *call_expression) override;
  void Visit(ExpressionList *expression_list) override;
  void Visit(NameExpression *name_expression) override;
  void Visit(EseqExpression *eseq_expression) override;
  Statement* GetTree();

};

}


