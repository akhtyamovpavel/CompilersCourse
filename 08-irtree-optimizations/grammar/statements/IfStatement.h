//
// Created by akhtyamovpavel on 4/7/20.
//


#pragma once

#include "Statement.h"
class IfStatement : public Statement {
 public:
  IfStatement(Expression* bool_expression, AssignmentList* true_statement, AssignmentList* false_statement);
  void Accept(Visitor *visitor) override;

  Expression* bool_expression_;
  AssignmentList* true_statement_;
  AssignmentList* false_statement_;

};


