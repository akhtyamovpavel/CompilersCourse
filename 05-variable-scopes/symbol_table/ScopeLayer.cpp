#include "ScopeLayer.h"

#include "objects/UninitObject.h"

#include <iostream>

ScopeLayer::ScopeLayer(std::shared_ptr<ScopeLayer> parent): std::enable_shared_from_this<ScopeLayer>(), parent_(parent) {
    std::cout << "Constructor called" << std::endl;
    std::cout << "End contstructor called" << std::endl;

    auto wptr = std::shared_ptr<ScopeLayer>( this, [](ScopeLayer*){} );

    auto parent_ptr = parent_.lock();
    if (parent_ptr != nullptr) {
        parent_ptr->AddChild(shared_from_this());
    }
}

void ScopeLayer::AttachParent() {
    
}

ScopeLayer::ScopeLayer(): std::enable_shared_from_this<ScopeLayer>(), parent_(std::weak_ptr<ScopeLayer>()) {}

void ScopeLayer::DeclareVariable(Symbol symbol) {
    if (values_.find(symbol) != values_.end()) {
        throw std::runtime_error("Variable has declared");
    }

    values_[symbol] = std::make_shared<UninitObject>();
}

void ScopeLayer::Put(Symbol symbol, std::shared_ptr<Object> value) {
    std::shared_ptr<ScopeLayer> current_layer = shared_from_this();

    while (!current_layer->Has(symbol) && current_layer->parent_.lock() != nullptr) {
        current_layer = current_layer->parent_.lock();
    }
    if (current_layer->Has(symbol)) {
        current_layer->values_.find(symbol)->second = value;
    } else {
        throw std::runtime_error("Variable not declared");
    }
}

bool ScopeLayer::Has(Symbol symbol) {
    return values_.find(symbol) != values_.end();
}


std::shared_ptr<Object> ScopeLayer::Get(Symbol symbol) {
    std::shared_ptr<ScopeLayer> current_layer = shared_from_this();

    while (!current_layer->Has(symbol) && current_layer->parent_.lock() != nullptr) {
        current_layer = current_layer->parent_.lock();
    }
    if (current_layer->Has(symbol)) {
        return current_layer->values_.find(symbol)->second;
    } else {
        throw std::runtime_error("Variable not declared");
    }


}

void ScopeLayer::AddChild(std::shared_ptr<ScopeLayer> child) {
    children_.push_back(child);
}

std::shared_ptr<ScopeLayer> ScopeLayer::GetParent() const {
    return parent_.lock();
}