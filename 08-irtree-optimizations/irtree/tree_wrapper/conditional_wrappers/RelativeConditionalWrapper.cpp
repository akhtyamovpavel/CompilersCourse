//
// Created by akhtyamovpavel on 4/14/20.
//

#include "RelativeConditionalWrapper.h"
#include "../../nodes/statements/JumpConditionalStatement.h"


namespace IRT {

Statement *RelativeConditionalWrapper::ToConditional(Label true_label, Label false_label) {
  return new JumpConditionalStatement(
    operator_type_,
    lhs_,
    rhs_,
    true_label,
    false_label
  );
}
RelativeConditionalWrapper::RelativeConditionalWrapper(
    LogicOperatorType type,
    Expression *lhs,
    Expression *rhs
): operator_type_(type), lhs_(lhs), rhs_(rhs)  {
}
}