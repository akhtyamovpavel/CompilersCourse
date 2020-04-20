//
// Created by akhtyamovpavel on 4/15/20.
//

#include "TemplateVisitor.h"
#include "VisitorStruct.h"

namespace IRT {
template<typename T>
T TemplateVisitor<T>::Accept(BaseElement * element) {
  element->Accept(this);
  return tos_value_;
}

template int TemplateVisitor<int>::Accept(BaseElement* element);
template IrtStorage TemplateVisitor<IrtStorage>::Accept(IRT::BaseElement *element);
}
