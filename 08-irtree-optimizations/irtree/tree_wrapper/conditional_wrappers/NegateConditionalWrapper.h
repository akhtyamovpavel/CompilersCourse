//
// Created by akhtyamovpavel on 4/8/20.
//


#pragma once

#include "ConditionalWrapper.h"
namespace IRT {
class NegateConditionalWrapper : public ConditionalWrapper {
 public:
  explicit NegateConditionalWrapper(SubtreeWrapper* wrapper);
  Statement *ToConditional(Label true_label, Label false_label) override;
 private:
  SubtreeWrapper* wrapper_;
};

}


