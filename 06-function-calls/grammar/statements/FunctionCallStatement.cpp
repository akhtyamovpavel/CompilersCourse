//
// Created by Pavel Akhtyamov on 25.03.2020.
//

#include "FunctionCallStatement.h"
FunctionCallStatement::FunctionCallStatement(const std::string &name, ParamList *param_list):
  param_list_(param_list),
  name_(name) {

}

void FunctionCallStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
