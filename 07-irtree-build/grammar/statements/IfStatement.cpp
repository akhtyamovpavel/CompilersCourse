//
// Created by akhtyamovpavel on 4/7/20.
//

#include "IfStatement.h"

void IfStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
IfStatement::IfStatement(
    Expression *bool_expression,
    StatementList *true_statement,
    StatementList *false_statement
    ): bool_expression_(bool_expression),
    true_statement_(true_statement),
    false_statement_(false_statement) {

}
