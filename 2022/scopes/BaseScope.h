//
// Created by akhtyamovpavel on 3/11/21.
//


#pragma once

#include <unordered_map>
#include <symbols/BaseSymbol.h>
#include <vector>

class BaseScope {
 public:
  std::unordered_map<std::string, BaseSymbol*> elements;
  std::vector<BaseScope*> children_;
  BaseScope* parent_;
};


