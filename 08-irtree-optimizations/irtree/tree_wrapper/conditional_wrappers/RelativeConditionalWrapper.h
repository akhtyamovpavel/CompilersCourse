//
// Created by akhtyamovpavel on 4/14/20.
//


#pragma once

#include "ConditionalWrapper.h"
#include "../../types/LogicOperatorType.h"


namespace IRT {
class RelativeConditionalWrapper: public ConditionalWrapper {
 public:
  RelativeConditionalWrapper(LogicOperatorType type, Expression *lhs, Expression *rhs);
  Statement *ToConditional(Label true_label, Label false_label) override;

  Expression* lhs_;
  Expression* rhs_;
  LogicOperatorType operator_type_;

};

}


