//
// Created by akhtyamovpavel on 4/7/20.
//


#pragma once

#include "Statement.h"

class IfStatement : public Statement {
 public:
  IfStatement(Expression* bool_expression, Statement* true_statement, Statement* false_statement);
  void Accept(Visitor *visitor) override;

  Expression* bool_expression_;
  Statement* true_statement_;
  Statement* false_statement_;

};


