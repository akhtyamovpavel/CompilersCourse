#include "VarDecl.h"

VarDecl::VarDecl(
    const std::string& variable
) : variable_(variable) {}


void VarDecl::Accept(Visitor* visitor) {
    visitor->Visit(this);
}