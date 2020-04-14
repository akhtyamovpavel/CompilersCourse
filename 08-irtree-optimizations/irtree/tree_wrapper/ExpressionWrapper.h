//
// Created by akhtyamovpavel on 4/7/20.
//


#pragma once

#include "SubtreeWrapper.h"
#include "../nodes/statements/Statement.h"
namespace IRT {

class ExpressionWrapper : public SubtreeWrapper {
 public:

  explicit ExpressionWrapper(Expression* expression);
  virtual ~ExpressionWrapper() = default;
  Expression *ToExpression() override;
  Statement *ToStatement() override;
  Statement *ToConditional(Label true_label, Label false_label) override;
 private:
  Expression* expression_;
};

}

