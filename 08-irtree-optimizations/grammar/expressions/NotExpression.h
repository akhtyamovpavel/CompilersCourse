//
// Created by akhtyamovpavel on 4/7/20.
//


#pragma once

#include "Expression.h"
class NotExpression : public Expression {
 public:
  explicit NotExpression(Expression* e1);
  void Accept(Visitor *visitor) override;

  Expression* expression_;
};


