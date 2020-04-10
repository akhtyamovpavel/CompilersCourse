//
// Created by akhtyamovpavel on 4/8/20.
//


#pragma once

#include "Statement.h"
#include "../expressions/Expression.h"
namespace IRT {

class MoveStatement : public Statement {
 public:
  MoveStatement(Expression *source, Expression *target);
  void Accept(Visitor *visitor) override;
  Expression* source_;
  Expression* target_;
};

};


