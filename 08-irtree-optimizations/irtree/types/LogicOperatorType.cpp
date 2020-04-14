//
// Created by akhtyamovpavel on 4/14/20.
//

#include "LogicOperatorType.h"
std::string IRT::ToString(IRT::LogicOperatorType type) {
  switch (type) {
    case LogicOperatorType::EQ:
      return "EQ";
    case LogicOperatorType::NE:
      return "NE";
    case LogicOperatorType::LT:
      return "LT";
    case LogicOperatorType::GT:
      return "GT";
  }
}
