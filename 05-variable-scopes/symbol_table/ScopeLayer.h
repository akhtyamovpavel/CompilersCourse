#pragma once

#include "Symbol.h"
#include "objects/Object.h"

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>


class ScopeLayer : public std::enable_shared_from_this<ScopeLayer> {
 public:
    explicit ScopeLayer(std::shared_ptr<ScopeLayer> parent);
    ScopeLayer();
    void DeclareVariable(Symbol symbol);
    void Put(Symbol symbol, std::shared_ptr<Object> value);
    std::shared_ptr<Object> Get(Symbol symbol);
    bool Has(Symbol symbol);

    void AddChild(std::shared_ptr<ScopeLayer> child);
    void AttachParent();

    std::shared_ptr<ScopeLayer> GetChild(size_t index);
    std::shared_ptr<ScopeLayer> GetParent() const;
 private:
    std::unordered_map<Symbol, std::shared_ptr<Object>> values_;
    std::unordered_map<Symbol, size_t> offsets_;
    std::vector<Symbol> symbols_;
    std::string name_;
    std::weak_ptr<ScopeLayer> parent_;
    std::vector<std::shared_ptr<ScopeLayer> > children_;
};