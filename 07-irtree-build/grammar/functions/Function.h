//
// Created by Pavel Akhtyamov on 24.03.2020.
//

#pragma once

#include <base_elements/BaseElement.h>

#include <statements/AssignmentList.h>
#include <functions/ParamList.h>
#include <string>

class Function : public BaseElement {
 public:
  Function(const std::string& name, ParamList* param_list, AssignmentList* statements);
  void Accept(Visitor *visitor) override;

  std::string name_;
  ParamList* param_list_;
  AssignmentList* statements_;

};



