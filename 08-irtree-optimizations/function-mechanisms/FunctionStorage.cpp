//
// Created by akhtyamovpavel on 4/5/20.
//

#include "FunctionStorage.h"

FunctionStorage &FunctionStorage::GetInstance() {
    static FunctionStorage storage;
    return storage;
}

void FunctionStorage::Set(Symbol symbol, Function *function) {
    functions_[symbol] = function;
}


Function *FunctionStorage::Get(Symbol symbol) const {
    if (functions_.find(symbol) != functions_.end()) {
        return functions_.at(symbol);
    } else {
        throw std::runtime_error("Function not found");
    }
}
