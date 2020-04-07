//
// Created by akhtyamovpavel on 4/7/20.
//


#pragma once

#include "Expression.h"

class AndExpression : public Expression {
 public:
  AndExpression(Expression* e1, Expression* e2);
  void Accept(Visitor *visitor) override;
  Expression* first;
  Expression* second;
};


