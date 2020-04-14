//
// Created by akhtyamovpavel on 4/14/20.
//

#include "JumpStatement.h"

namespace IRT {

void JumpStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);

}
JumpStatement::JumpStatement(Label label): label_(label) {

}
}