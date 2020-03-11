#pragma once

#include "ScopeLayer.h"

class ScopeLayerTree {
 public:
    explicit ScopeLayerTree(std::shared_ptr<ScopeLayer> root);
 public:
    std::shared_ptr<ScopeLayer> root_;
};