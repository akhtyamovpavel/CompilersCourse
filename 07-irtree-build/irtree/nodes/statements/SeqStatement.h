//
// Created by akhtyamovpavel on 4/8/20.
//


#pragma once
#include "Statement.h"
namespace IRT {
class SeqStatement : public Statement {
 public:
  SeqStatement(Statement* first, Statement* second);
  void Accept(Visitor *visitor) override;
  Statement* first_statement_;
  Statement* second_statement_;
};

}


