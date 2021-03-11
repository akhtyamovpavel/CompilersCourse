//
// Created by akhtyamovpavel on 4/7/20.
//


#pragma once

#include "Statement.h"
class IfStatement : public Statement {
 public:
  IfStatement(Expression* bool_expression, StatementList* true_statement, StatementList* false_statement);
  void Accept(Visitor *visitor) override;

  Expression* bool_expression_;
  StatementList* true_statement_;
  StatementList* false_statement_;

};


