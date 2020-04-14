#pragma once

#include "Type.h"

class UninitObject: public Type {
 public:
    // explicit Integer(int value);
    int ToInt() override;
    // int value_;
};