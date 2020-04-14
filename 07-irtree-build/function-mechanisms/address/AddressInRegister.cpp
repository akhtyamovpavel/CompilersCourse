//
// Created by akhtyamovpavel on 4/14/20.
//

#include "AddressInRegister.h"

#include <irtree/nodes/expressions/TempExpression.h>

namespace IRT {
Expression *AddressInRegister::ToExpression() {
  return new TempExpression(temp_);
}
AddressInRegister::AddressInRegister(const Temporary &temp)
: temp_(temp) {

}

}
