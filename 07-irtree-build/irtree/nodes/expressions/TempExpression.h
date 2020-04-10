//
// Created by akhtyamovpavel on 4/10/20.
//


#pragma once

#include "../expressions/Expression.h"
#include "../../generators/Temporary.h"
namespace IRT {
class TempExpression : public Expression {
 public:
  explicit TempExpression(const IRT::Temporary &temporary);
  void Accept(Visitor *visitor) override;
  Temporary temporary_;
};

}


