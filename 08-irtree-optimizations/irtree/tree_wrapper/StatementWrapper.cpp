//
// Created by akhtyamovpavel on 4/8/20.
//

#include <cassert>
#include "StatementWrapper.h"

namespace IRT {

Expression *StatementWrapper::ToExpression() {
  assert(false);
}
Statement *StatementWrapper::ToStatement() {
  return statement_;
}

Statement *StatementWrapper::ToConditional(Label true_label, Label false_label) {
  assert(false);
}

StatementWrapper::StatementWrapper(Statement *statement): statement_(statement) {

}

}