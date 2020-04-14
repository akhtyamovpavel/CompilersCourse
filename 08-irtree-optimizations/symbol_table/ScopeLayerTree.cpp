#include "ScopeLayerTree.h"

ScopeLayerTree::ScopeLayerTree(ScopeLayer* root) : root_(root) {}

ScopeLayerTree::~ScopeLayerTree() {

}

void ScopeLayerTree::PrintTree(const std::string& filename) {
  stream_ = std::ofstream(filename);

  root_->PrintLayer(stream_, 0);

  stream_.close();

}
ScopeLayerTree::ScopeLayerTree(const ScopeLayerTree &other) {
  root_ = other.root_;
  layer_mapping_ = other.layer_mapping_;
}

void ScopeLayerTree::AddMapping(Symbol name, ScopeLayer *layer) {
  if (layer_mapping_.find(name) != layer_mapping_.end()) {
    throw std::runtime_error("Function has already been declared");
  }
  layer_mapping_[name] = layer;
}

ScopeLayer *ScopeLayerTree::GetFunctionScopeByName(Symbol name) {
  if (layer_mapping_.find(name) == layer_mapping_.end()) {
    throw std::runtime_error("No such function");
  }
  return layer_mapping_[name];
}

std::shared_ptr<Type> ScopeLayerTree::Get(Symbol symbol) {
  return root_->Get(symbol);
}
