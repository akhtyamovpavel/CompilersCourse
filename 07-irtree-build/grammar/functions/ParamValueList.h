//
// Created by akhtyamovpavel on 4/5/20.
//


#pragma once


#include <vector>
#include "base_elements/BaseElement.h"

class ParamValueList : public BaseElement {
public:
    ParamValueList() = default;
    explicit ParamValueList(Expression* param);
    void Accept(Visitor *visitor) override;
    void AddParam(Expression* expression);

    std::vector<Expression*> params_;
};
