//
// Created by akhtyamovpavel on 4/8/20.
//


#pragma once

#include "../SubtreeWrapper.h"
namespace IRT {

class ConditionalWrapper : public SubtreeWrapper {
 public:
  virtual ~ConditionalWrapper() = default;
  Expression *ToExpression() override;
  Statement *ToStatement() override;

};

}


