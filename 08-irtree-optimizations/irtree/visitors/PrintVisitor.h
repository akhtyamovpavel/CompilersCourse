//
// Created by akhtyamovpavel on 4/14/20.
//


#pragma once

#include <string>
#include <fstream>
#include "Visitor.h"
namespace IRT {
class PrintVisitor: public Visitor {

 public:
  explicit PrintVisitor(const std::string& filename);
  ~PrintVisitor() override ;
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

 private:
  std::ofstream stream_;
  int num_tabs_ = 0;

  void PrintTabs();

};

}

