//
// Created by Pavel Akhtyamov on 25.03.2020.
//

#pragma once

#include "Statement.h"

#include <string>

class FunctionCallStatement: public Statement {
 public:
  FunctionCallStatement(const std::string& name, ParamList* param_list);
  void Accept(Visitor *visitor) override;
  std::string name_;
  ParamList* param_list_;
};



