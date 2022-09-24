//
// Created by akhtyamovpavel on 4/20/20.
//

#include "EseqEliminateVisitor.h"

#include "BaseElements.h"

namespace IRT {

void EseqEliminateVisitor::Visit(ExpStatement *stmt) {

}
void EseqEliminateVisitor::Visit(ConstExpression *const_expression) {

}
void EseqEliminateVisitor::Visit(JumpConditionalStatement *jump_conditional_statement) {

}
void EseqEliminateVisitor::Visit(MoveStatement *move_statement) {

}
void EseqEliminateVisitor::Visit(SeqStatement *seq_statement) {

}
void EseqEliminateVisitor::Visit(LabelStatement *label_statement) {

}
void EseqEliminateVisitor::Visit(BinopExpression *binop_statement) {

}
void EseqEliminateVisitor::Visit(TempExpression *temp_exression) {
  tos_value_.expression_ = new TempExpression(temp_exression->temporary_);
}

void EseqEliminateVisitor::Visit(MemExpression *mem_expression) {
  auto expression = Accept(mem_expression->expression_).expression_;

  auto eseq_expr = CastToEseq(expression);

  if (eseq_expr) {
    tos_value_.expression_ = new EseqExpression(
      eseq_expr->statement_,
      new MemExpression(eseq_expr->expression_)
    );
  } else {
    tos_value_.expression_ = new MemExpression(expression);
  }
}
void EseqEliminateVisitor::Visit(JumpStatement *jump_statement) {
  tos_value_.statement_ = new JumpStatement(
      jump_statement->label_
  );
}

void EseqEliminateVisitor::Visit(CallExpression *call_expression) {

}

void EseqEliminateVisitor::Visit(ExpressionList *expression_list) {

}
void EseqEliminateVisitor::Visit(NameExpression *name_expression) {

}
void EseqEliminateVisitor::Visit(EseqExpression *eseq_expression) {
  auto stmt = Accept(eseq_expression->statement_).statement_;
  auto expr = Accept(eseq_expression->expression_).expression_;

  auto eseq_expr = CastToEseq(expr);

  if (eseq_expr) {
    tos_value_.expression_ = new EseqExpression(
      new SeqStatement(stmt, eseq_expr->statement_),
      eseq_expr->expression_
    );
  } else {
    tos_value_.expression_ = new EseqExpression(
      stmt, expr
    );
  }
}
EseqExpression *EseqEliminateVisitor::CastToEseq(Expression *expression) {
  return dynamic_cast<EseqExpression*>(expression);
}
}
