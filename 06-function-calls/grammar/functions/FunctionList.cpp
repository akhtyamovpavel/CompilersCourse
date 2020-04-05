//
// Created by Pavel Akhtyamov on 25.03.2020.
//

#include "FunctionList.h"

void FunctionList::Accept(Visitor *visitor) {
  visitor->Visit(this);
}

FunctionList::FunctionList(Function *function) {
  functions_.push_back(function);
}

void FunctionList::AddFunction(Function *function) {
  functions_.push_back(function);
}


