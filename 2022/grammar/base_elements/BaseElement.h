#pragma once

#include "visitors/Visitor.h"

class BaseElement {
 public:
    virtual void Accept(Visitor* visitor) = 0;
    virtual ~BaseElement() = default;
};
