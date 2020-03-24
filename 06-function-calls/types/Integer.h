#pragma once

#include "Type.h"

class Integer: public Type {
 public:
    explicit Integer(int value);
    int ToInt() override;
 private:
    int value_;
};