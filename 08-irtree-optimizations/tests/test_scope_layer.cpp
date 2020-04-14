#include "symbol_table/ScopeLayer.h"
#include "symbol_table/Symbol.h"

#include "objects/Integer.h"

#include <iostream>

int main() {
    std::shared_ptr<ScopeLayer> layer = std::make_shared<ScopeLayer>();
    // ScopeLayer layer;

    layer->DeclareVariable(Symbol("a"));
    layer->Put(Symbol("a"), std::make_shared<Integer>(2));

    std::cout << layer->Get(Symbol("a"))->ToInt() << std::endl;

    auto layer2 = std::make_shared<ScopeLayer>(layer);
    layer2->AttachParent();

    std::cout << layer2->Get(Symbol("a"))->ToInt() << std::endl;

    layer->Put(Symbol("a"), std::make_shared<Integer>(3));
    std::cout << layer2->Get(Symbol("a"))->ToInt() << std::endl;
    std::cout << layer->Get(Symbol("a"))->ToInt() << std::endl;

    layer2->DeclareVariable(Symbol("a"));
    layer2->Put(Symbol("a"), std::make_shared<Integer>(4));
    std::cout << layer2->Get(Symbol("a"))->ToInt() << std::endl;
    std::cout << layer->Get(Symbol("a"))->ToInt() << std::endl;
}