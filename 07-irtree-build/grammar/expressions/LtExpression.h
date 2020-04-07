//
// Created by akhtyamovpavel on 4/7/20.
//


#pragma once

#include "Expression.h"
class LtExpression : public Expression {
 public:
  LtExpression(Expression* first, Expression* second);
  void Accept(Visitor *visitor) override;

  Expression* first;
  Expression* second;
};


