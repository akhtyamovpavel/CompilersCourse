//
// Created by akhtyamovpavel on 3/11/21.
//

#include "BaseScope.h"

#include <iostream>

namespace symbols {
BaseScope::BaseScope(BaseScope* parent): parent_(parent) {}

BaseSymbol* BaseScope::GetVariable(const std::string& name, bool only_this) const {

    std::cout << "FIND " << name << std::endl;
    auto iterator = elements.find(name);
    if (iterator == elements.end()) {
        if (parent_ && !only_this) {
            return parent_->GetVariable(name, false);
        } else {
            return nullptr;
        }
    } else {
        return iterator->second;
    }
}

BaseScope* BaseScope::GetNamedScope(const std::string& name) {
    return named_children_[name];
}

BaseScope* BaseScope::GetScope(size_t index) {
    return children_[index];
}

}