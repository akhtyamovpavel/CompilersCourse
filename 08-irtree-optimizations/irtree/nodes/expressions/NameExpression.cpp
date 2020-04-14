//
// Created by akhtyamovpavel on 4/14/20.
//

#include "NameExpression.h"

namespace IRT {

void NameExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);

}
NameExpression::NameExpression(Label label): label_(label) {

}

}