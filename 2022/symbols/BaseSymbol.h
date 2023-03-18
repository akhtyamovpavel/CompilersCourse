//
// Created by akhtyamovpavel on 3/11/21.
//


#pragma once

#include <string>

namespace symbols {

  class BaseSymbol {
  public:
    std::string name;
    std::string base_type;
    std::string type;
    virtual ~BaseSymbol() = default;
  };
}


