//
// Created by akhtyamovpavel on 4/5/20.
//

#include "FunctionCallExpression.h"


FunctionCallExpression::FunctionCallExpression(const std::string &name, ParamValueList *param_list):
        param_list_(param_list),
        name_(name) {

}

void FunctionCallExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);

}
