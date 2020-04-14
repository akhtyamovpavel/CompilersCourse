//
// Created by akhtyamovpavel on 4/7/20.
//


#pragma once

#include "Expression.h"
class OrExpression : public Expression {
 public:
  void Accept(Visitor *visitor) override;

 public:
  OrExpression(Expression* e1, Expression* e2);
  Expression* first;
  Expression* second;

};


