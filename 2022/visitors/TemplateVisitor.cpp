//
// Created by akhtyamovpavel on 3/11/21.
//

#include <scopes/BaseScope.h>
#include <llvm/IR/Value.h>
#include "TemplateVisitor.h"

#include "elements.h"

template <typename T>
T TemplateVisitor<T>::Accept(BaseElement *element) {
  element->Accept(this);
  return tos_value_;
}

template int TemplateVisitor<int>::Accept(BaseElement *element);

template PrimitiveTypeHolder TemplateVisitor<PrimitiveTypeHolder>::Accept(BaseElement *element);
template symbols::BaseScope* TemplateVisitor<symbols::BaseScope*>::Accept(BaseElement *element);
template llvm::Value* TemplateVisitor<llvm::Value*>::Accept(BaseElement *element);

template<typename T>
void TemplateVisitor<T>::SetValue(T value) {
  tos_value_ = value;
}

template void TemplateVisitor<int>::SetValue(int value);


template void TemplateVisitor<symbols::BaseScope*>::SetValue(symbols::BaseScope* value);

template void TemplateVisitor<llvm::Value*>::SetValue(llvm::Value* value);