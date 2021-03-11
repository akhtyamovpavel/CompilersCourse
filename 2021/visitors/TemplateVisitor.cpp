//
// Created by akhtyamovpavel on 3/11/21.
//

#include <scopes/BaseScope.h>
#include "TemplateVisitor.h"

#include "elements.h"

template <typename T>
T TemplateVisitor<T>::Accept(BaseElement *element) {
  element->Accept(this);
  return tos_value_;
}

template int TemplateVisitor<int>::Accept(BaseElement *element);

template PrimitiveTypeHolder TemplateVisitor<PrimitiveTypeHolder>::Accept(BaseElement *element);
template BaseScope* TemplateVisitor<BaseScope*>::Accept(BaseElement *element);

template<typename T>
void TemplateVisitor<T>::SetValue(T value) {
  tos_value_ = value;
}

template void TemplateVisitor<int>::SetValue(int value);


template void TemplateVisitor<BaseScope*>::SetValue(BaseScope* value);