//
// Created by akhtyamovpavel on 4/8/20.
//


#pragma once

#include "ConditionalWrapper.h"
namespace IRT {

class AndConditionalWrapper : public ConditionalWrapper {
 public:
  AndConditionalWrapper(SubtreeWrapper* first, SubtreeWrapper* second);
  Statement *ToConditional(Label true_label, Label false_label) override;
 private:
  SubtreeWrapper* first_;
  SubtreeWrapper* second_;
};

}

