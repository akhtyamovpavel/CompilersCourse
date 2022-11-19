//
// Created by akhtyamovpavel on 3/11/21.
//


#pragma once

#include <unordered_map>
#include <symbols/BaseSymbol.h>
#include <vector>

class BaseScope {
 public:
  explicit BaseScope(BaseScope* parent = nullptr);
  std::unordered_map<std::string, BaseSymbol*> elements;
  std::vector<BaseScope*> children_;
  std::unordered_map<std::string, BaseScope*> named_children_;
  BaseScope* parent_ = nullptr;

  BaseSymbol* GetVariable(const std::string& name, bool only_this = false) const;
};


