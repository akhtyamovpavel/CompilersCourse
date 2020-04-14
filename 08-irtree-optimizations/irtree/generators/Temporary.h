//
// Created by akhtyamovpavel on 4/7/20.
//


#pragma once

#include <string>
namespace IRT {
class Temporary {
 public:
  Temporary();
  explicit Temporary(const std::string& name);
  std::string ToString() const;
 private:
  std::string name_;
  static int counter_;
};

}

