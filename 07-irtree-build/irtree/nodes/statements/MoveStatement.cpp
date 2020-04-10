//
// Created by akhtyamovpavel on 4/8/20.
//

#include "MoveStatement.h"
namespace IRT {
void MoveStatement::Accept(IRT::Visitor *visitor) {
  visitor->Visit(this);
}
MoveStatement::MoveStatement(
    Expression *source,
    Expression *target
  ): source_(source), target_(target) {

}

}
