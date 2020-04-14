//
// Created by akhtyamovpavel on 4/14/20.
//


#pragma once

#include "Address.h"
namespace IRT {

class AddressInFrame: public Address {
 public:
  AddressInFrame(
    Address* frame_address,
    int offset
  );
  ~AddressInFrame() = default;
  Expression *ToExpression() override;
 private:
  Address* frame_address_;
  int offset_;

};

}
