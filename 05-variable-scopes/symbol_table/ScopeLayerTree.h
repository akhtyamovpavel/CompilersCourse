#pragma once

#include "ScopeLayer.h"

class ScopeLayerTree {
 public:
    explicit ScopeLayerTree(ScopeLayer* root);
 public:
    ScopeLayer* root_;
};