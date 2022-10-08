#pragma once


#include "Statement.h"

class ReturnStatement : public Statement {
public:
    void Accept(Visitor *visitor) override;
    explicit ReturnStatement(Expression* expression);

    Expression* return_expression_;
};


