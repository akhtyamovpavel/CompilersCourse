//
// Created by akhtyamovpavel on 4/7/20.
//

#include "ExpressionWrapper.h"
#include "../nodes/statements/ExpStatement.h"
#include "../nodes/statements/JumpConditionalStatement.h"
#include "../nodes/expressions/ConstExpression.h"

IRT::Expression *IRT::ExpressionWrapper::ToExpression() {
  return expression_;
}

IRT::Statement *IRT::ExpressionWrapper::ToStatement() {
  return new ExpStatement(expression_);
}

IRT::Statement *IRT::ExpressionWrapper::ToConditional(IRT::Label true_label, IRT::Label false_label) {
  return new JumpConditionalStatement(
      LogicOperatorType::NE,
      expression_,
      new ConstExpression(0),
      true_label,
      false_label
  );
}

IRT::ExpressionWrapper::ExpressionWrapper(IRT::Expression *expression): expression_(expression) {

}
