//
// Created by Pavel Akhtyamov on 24.03.2020.
//

#include "Function.h"

void Function::Accept(Visitor *visitor) {
  visitor->Visit(this);
}

Function::Function(
    const std::string &name,
    ParamList *param_list,
    AssignmentList *statements): name_(name), param_list_(param_list), statements_(statements){
}
