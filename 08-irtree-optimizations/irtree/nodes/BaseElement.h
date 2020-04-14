#pragma once

#include "../visitors/Visitor.h"
namespace IRT {

class BaseElement {
 public:
  virtual ~BaseElement() = default;
  virtual void Accept(Visitor* visitor) = 0;
};
}
