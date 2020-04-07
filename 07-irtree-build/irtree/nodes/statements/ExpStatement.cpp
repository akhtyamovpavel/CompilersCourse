//
// Created by akhtyamovpavel on 4/7/20.
//

#include "ExpStatement.h"

using namespace IRT;

Expression *ExpStatement::GetExpression() {
  return expression_;
}

ExpStatement::ExpStatement(Expression *expression): expression_(expression) {

}

void ExpStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);

}
