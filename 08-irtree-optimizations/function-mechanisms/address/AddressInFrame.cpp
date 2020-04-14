//
// Created by akhtyamovpavel on 4/14/20.
//

#include "AddressInFrame.h"

#include <irtree/nodes/expressions/BinopExpression.h>
#include <irtree/nodes/expressions/ConstExpression.h>
#include <irtree/nodes/expressions/MemExpression.h>


namespace IRT {
Expression *AddressInFrame::ToExpression() {
  Expression* offset_expression;
  if (offset_ != 0) {
    offset_expression = new BinopExpression(
      BinaryOperatorType::PLUS,
      frame_address_->ToExpression(),
      new ConstExpression(offset_)
    );
  } else {
    offset_expression = frame_address_->ToExpression();
  }
  return new MemExpression(offset_expression);
}

AddressInFrame::AddressInFrame(
    Address *frame_address, int offset
) : frame_address_(frame_address), offset_(offset) {

}

}