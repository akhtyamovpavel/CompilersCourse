//
// Created by akhtyamovpavel on 4/8/20.
//

#include <irtree/tree_wrapper/ExpressionWrapper.h>
#include <irtree/nodes/expressions/ConstExpression.h>
#include <grammar/expressions/NumberExpression.h>
#include <grammar/expressions/NotExpression.h>
#include <irtree/tree_wrapper/conditional_wrappers/NegateConditionalWrapper.h>
#include <irtree/tree_wrapper/conditional_wrappers/AndConditionalWrapper.h>
#include <grammar/expressions/AndExpression.h>
#include <grammar/expressions/OrExpression.h>
#include <irtree/tree_wrapper/conditional_wrappers/OrConditionalWrapper.h>
#include <grammar/statements/Assignment.h>
#include <irtree/types/BinaryOperatorType.h>
#include <irtree/generators/Temporary.h>
#include <irtree/nodes/expressions/BinopExpression.h>
#include <irtree/nodes/expressions/TempExpression.h>
#include <irtree/nodes/expressions/MemExpression.h>
#include <irtree/nodes/statements/MoveStatement.h>
#include <irtree/tree_wrapper/StatementWrapper.h>
#include "IrtreeBuildVisitor.h"

void IrtreeBuildVisitor::Visit(NumberExpression *expression) {
  tos_value_ = new IRT::ExpressionWrapper(
    new IRT::ConstExpression(expression->value_)
  );
}

void IrtreeBuildVisitor::Visit(AddExpression *expression) {

}
void IrtreeBuildVisitor::Visit(SubstractExpression *expression) {

}
void IrtreeBuildVisitor::Visit(MulExpression *expression) {

}
void IrtreeBuildVisitor::Visit(DivExpression *expression) {

}
void IrtreeBuildVisitor::Visit(IdentExpression *expression) {
  // get_offset
  // BINOP(+, FP(), offset * word_size)
}
void IrtreeBuildVisitor::Visit(Assignment *assignment) {
  int offset = 0; // frame->GetOffset(variable);
//  auto lvalue = Accept();
  auto rvalue = Accept(assignment->expression_);
  auto fp = IRT::Temporary(); // TODO -> move to frame

  tos_value_ = new IRT::StatementWrapper(new IRT::MoveStatement(
      new IRT::MemExpression(
          new IRT::BinopExpression(
              IRT::BinaryOperatorType::PLUS,
              new IRT::TempExpression(fp),
              new IRT::ConstExpression(offset)
              )
          ),
      rvalue->ToExpression()
  )
  );
  // MOVE(MEM(
}
void IrtreeBuildVisitor::Visit(VarDecl *var_decl) {

}
void IrtreeBuildVisitor::Visit(PrintStatement *statement) {

}
void IrtreeBuildVisitor::Visit(AssignmentList *assignment_list) {

}
void IrtreeBuildVisitor::Visit(ScopeAssignmentList *list) {

}
void IrtreeBuildVisitor::Visit(Program *program) {

}
void IrtreeBuildVisitor::Visit(ParamList *param_list) {

}
void IrtreeBuildVisitor::Visit(Function *function) {

}
void IrtreeBuildVisitor::Visit(FunctionCallExpression *statement) {

}
void IrtreeBuildVisitor::Visit(FunctionList *function_list) {

}
void IrtreeBuildVisitor::Visit(ParamValueList *value_list) {

}
void IrtreeBuildVisitor::Visit(ReturnStatement *return_statement) {

}
void IrtreeBuildVisitor::Visit(AndExpression *and_expression) {
  auto first_wrapper = Accept(and_expression->first);
  auto second_wrapper = Accept(and_expression->second);

  tos_value_ = new IRT::AndConditionalWrapper(
      first_wrapper,
      second_wrapper
  );
}

void IrtreeBuildVisitor::Visit(OrExpression *or_expression) {
  auto first_wrapper = Accept(or_expression->first);
  auto second_wrapper = Accept(or_expression->second);

  tos_value_ = new IRT::OrConditionalWrapper(
    first_wrapper,
    second_wrapper
  );
}

void IrtreeBuildVisitor::Visit(NotExpression *not_expression) {
  auto wrapper = Accept(not_expression->expression_);

  tos_value_ = new IRT::NegateConditionalWrapper(
      wrapper
  );
}
void IrtreeBuildVisitor::Visit(IfStatement *if_statement) {

}
void IrtreeBuildVisitor::Visit(GtExpression *gt_expression) {

}
void IrtreeBuildVisitor::Visit(LtExpression *lt_expression) {

}
