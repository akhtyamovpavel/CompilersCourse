//
// Created by akhtyamovpavel on 4/8/20.
//

#pragma once

#include <string>
namespace IRT {
enum class LogicOperatorType : char {
  LT,
  GT,
  EQ,
  NE
};

std::string ToString(LogicOperatorType type);
}
