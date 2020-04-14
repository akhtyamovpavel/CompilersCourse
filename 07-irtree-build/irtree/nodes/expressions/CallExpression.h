//
// Created by akhtyamovpavel on 4/14/20.
//


#pragma once

#include "Expression.h"
namespace IRT {
class CallExpression: public Expression {
 public:
  CallExpression(Expression *expression, ExpressionList *args);
  void Accept(Visitor *visitor) override;
  Expression* function_name_;
  ExpressionList* args_;

};
}


