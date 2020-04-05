//
// Created by akhtyamovpavel on 4/5/20.
//

#include "ReturnStatement.h"

void ReturnStatement::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

ReturnStatement::ReturnStatement(Expression *expression): return_expression_(expression) {

}
