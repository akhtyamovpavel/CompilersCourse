//
// Created by akhtyamovpavel on 4/15/20.
//


#pragma once

#include "Visitor.h"
#include "../nodes/BaseElement.h"
namespace IRT {
template<typename T>
class TemplateVisitor : public Visitor {
 public:
  T Accept(BaseElement* element);
 protected:
  T tos_value_;

};

}


