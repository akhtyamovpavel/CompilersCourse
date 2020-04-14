//
// Created by akhtyamovpavel on 4/7/20.
//

#include "Temporary.h"
IRT::Temporary::Temporary(): name_("%" + std::to_string(counter_++)) {

}
std::string IRT::Temporary::ToString() const {
  return name_;
}

int IRT::Temporary::counter_ = 0;
IRT::Temporary::Temporary(const std::string &name): name_(name) {

}


