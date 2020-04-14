#include <irtree/tree_wrapper/SubtreeWrapper.h>
#include "TemplateVisitor.h"

#include "elements.h"

template<typename T>
T TemplateVisitor<T>::Accept(BaseElement * element) {
    element->Accept(this);
    return tos_value_;
}

template int TemplateVisitor<int>::Accept(BaseElement* element);
template IRT::SubtreeWrapper* TemplateVisitor<IRT::SubtreeWrapper*>::Accept(BaseElement *element);