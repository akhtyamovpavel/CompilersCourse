#pragma once

#include "Object.h"

class UninitObject: public Object {
 public:
    // explicit Integer(int value);
    int ToInt() override;
    // int value_;
};