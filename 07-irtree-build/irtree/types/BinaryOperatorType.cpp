//
// Created by akhtyamovpavel on 4/14/20.
//

#include "BinaryOperatorType.h"

std::string IRT::ToString(BinaryOperatorType type) {
  switch (type) {
    case BinaryOperatorType::PLUS:
      return "PLUS";
    case BinaryOperatorType::MINUS:
      return "MINUS";
    case BinaryOperatorType::MUL:
      return "MUL";
    case BinaryOperatorType::DIV:
      return "DIV";
    case BinaryOperatorType::AND:
      return "AND";
    case BinaryOperatorType::OR:
      return "OR";
  }
}

