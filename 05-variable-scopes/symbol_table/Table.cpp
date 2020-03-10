#include "Table.h"

#include <utility>

Table::Table() {}

void Table::Put(Symbol symbol, std::shared_ptr<Object> value) {
    values_[symbol] = value;
}

std::shared_ptr<Object> Table::Get(Symbol key) {
    return values_[key];
}

void Table::BeginScope() {}

void Table::EndScope() {}

Symbol Table::GetSymbol(const std::string& name) {
    auto it = symbols_map_.find(name);

    if (it == symbols_map_.end()) {
        Symbol symbol(name);
        symbols_map_.insert({name, symbol});
        // symbols_map_[name] = symbol;
        return symbol;
    } else {
        return it->second;
    }
}
