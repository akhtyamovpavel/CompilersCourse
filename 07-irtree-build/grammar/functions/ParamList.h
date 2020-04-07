//
// Created by Pavel Akhtyamov on 24.03.2020.
//

#pragma once

#include <string>
#include <vector>
#include <base_elements/BaseElement.h>

class ParamList : public BaseElement {
 public:
  ParamList();
  explicit ParamList(const std::string& param);
  void Accept(Visitor *visitor) override;
  void AddParam(const std::string& param);
 public:
  std::vector<std::string> params_;
};



