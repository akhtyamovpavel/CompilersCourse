#include "IdentExpression.h"
#include <driver.hh>

IdentExpression::IdentExpression(const std::string& ident): ident_(ident) {}

int IdentExpression::eval(const Driver& driver) const {
    return driver.variables.at(ident_);
}