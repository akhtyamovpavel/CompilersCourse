//
// Created by akhtyamovpavel on 4/5/20.
//

#include "ParamValueList.h"

void ParamValueList::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

void ParamValueList::AddParam(Expression *expression) {
    params_.push_back(expression);
}

ParamValueList::ParamValueList(Expression *param) {
    params_.push_back(param);

}
