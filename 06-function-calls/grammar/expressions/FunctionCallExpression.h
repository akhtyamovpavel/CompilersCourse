#pragma once


#include "Expression.h"

#include <string>

class FunctionCallExpression: public Expression {
public:
    FunctionCallExpression(const std::string& name, ParamValueList* param_list);
    void Accept(Visitor *visitor) override;
    std::string name_;
    ParamValueList* param_list_;
};


