//
// Created by akhtyamovpavel on 4/8/20.
//


#pragma once

#include "SubtreeWrapper.h"
namespace IRT {
class StatementWrapper : public SubtreeWrapper {
 public:
  explicit StatementWrapper(Statement* statement);
  Expression *ToExpression() override;
  Statement *ToStatement() override;
  Statement *ToConditional(Label true_label, Label false_label) override;
 private:
  Statement* statement_;
};

}

