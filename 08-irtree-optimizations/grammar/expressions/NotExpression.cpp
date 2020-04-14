//
// Created by akhtyamovpavel on 4/7/20.
//

#include "NotExpression.h"
void NotExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);

}
NotExpression::NotExpression(Expression *e1): expression_(e1) {
}
