#pragma once

#include "Symbol.h"
#include "objects/Object.h"

#include <unordered_map>

class Table {
 public:
    Table();
    void Put(Symbol symbol, std::shared_ptr<Object> value);

    Symbol GetSymbol(const std::string& name);

    std::shared_ptr<Object> Get(Symbol key);
    
    void BeginScope();
    void EndScope();
 private:
    std::unordered_map<Symbol, std::shared_ptr<Object>> values_;
    std::unordered_map<std::string, Symbol> symbols_map_;

};