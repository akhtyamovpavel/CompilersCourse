//
// Created by akhtyamovpavel on 4/8/20.
//

#include "LabelStatement.h"

namespace IRT {

void LabelStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);

}
LabelStatement::LabelStatement(IRT::Label label): label_(label) {

}
}