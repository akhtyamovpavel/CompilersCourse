//
// Created by akhtyamovpavel on 4/8/20.
//

#include <irtree/tree_wrapper/ExpressionWrapper.h>
#include <irtree/nodes/expressions/ConstExpression.h>
#include <grammar/expressions/NumberExpression.h>
#include <grammar/expressions/NotExpression.h>
#include <irtree/tree_wrapper/conditional_wrappers/NegateConditionalWrapper.h>
#include <irtree/tree_wrapper/conditional_wrappers/AndConditionalWrapper.h>
#include <grammar/expressions/AndExpression.h>
#include <grammar/expressions/OrExpression.h>
#include <irtree/tree_wrapper/conditional_wrappers/OrConditionalWrapper.h>
#include <grammar/statements/Assignment.h>
#include <irtree/types/BinaryOperatorType.h>
#include <irtree/generators/Temporary.h>
#include <irtree/nodes/expressions/BinopExpression.h>
#include <irtree/nodes/expressions/TempExpression.h>
#include <irtree/nodes/expressions/MemExpression.h>
#include <irtree/nodes/statements/MoveStatement.h>
#include <irtree/tree_wrapper/StatementWrapper.h>
#include <irtree/nodes/statements/LabelStatement.h>
#include <irtree/nodes/statements/SeqStatement.h>
#include <irtree/nodes/statements/JumpStatement.h>
#include <irtree/nodes/ExpressionList.h>
#include <irtree/nodes/expressions/CallExpression.h>
#include <irtree/nodes/expressions/NameExpression.h>
#include <irtree/types/LogicOperatorType.h>
#include <irtree/tree_wrapper/conditional_wrappers/RelativeConditionalWrapper.h>
#include "elements.h"

#include "IrtreeBuildVisitor.h"

void IrtreeBuildVisitor::Visit(NumberExpression *expression) {
  tos_value_ = new IRT::ExpressionWrapper(
    new IRT::ConstExpression(expression->value_)
  );
}

void IrtreeBuildVisitor::Visit(AddExpression *expression) {
  auto lhs = Accept(expression->first);
  auto rhs = Accept(expression->second);

  tos_value_ = new IRT::ExpressionWrapper(
      new IRT::BinopExpression(
      IRT::BinaryOperatorType::PLUS,
      lhs->ToExpression(),
      rhs->ToExpression()
    )
  );
}

void IrtreeBuildVisitor::Visit(SubstractExpression *expression) {
  auto lhs = Accept(expression->first);
  auto rhs = Accept(expression->second);

  tos_value_ = new IRT::ExpressionWrapper(
      new IRT::BinopExpression(
          IRT::BinaryOperatorType::MINUS,
          lhs->ToExpression(),
          rhs->ToExpression()
      )
  );
}
void IrtreeBuildVisitor::Visit(MulExpression *expression) {
  auto lhs = Accept(expression->first);
  auto rhs = Accept(expression->second);

  tos_value_ = new IRT::ExpressionWrapper(
      new IRT::BinopExpression(
          IRT::BinaryOperatorType::MUL,
          lhs->ToExpression(),
          rhs->ToExpression()
      )
  );
}

void IrtreeBuildVisitor::Visit(DivExpression *expression) {
  auto lhs = Accept(expression->first);
  auto rhs = Accept(expression->second);

  tos_value_ = new IRT::ExpressionWrapper(
      new IRT::BinopExpression(
          IRT::BinaryOperatorType::DIV,
          lhs->ToExpression(),
          rhs->ToExpression()
      )
  );
}


void IrtreeBuildVisitor::Visit(IdentExpression *expression) {
  auto address = current_frame_->GetAddress(expression->ident_);

  tos_value_ = new IRT::ExpressionWrapper(address->ToExpression());
}

void IrtreeBuildVisitor::Visit(Assignment *assignment) {
  auto var_expression = current_frame_->GetAddress(
      assignment->variable_
  )->ToExpression();
  auto rvalue = Accept(assignment->expression_);

  tos_value_ = new IRT::StatementWrapper(new IRT::MoveStatement(
      var_expression,
      rvalue->ToExpression()
  )
  );
}

void IrtreeBuildVisitor::Visit(VarDecl *var_decl) {
  current_frame_->AddLocalVariable(var_decl->variable_);
  tos_value_ = nullptr;
}

void IrtreeBuildVisitor::Visit(PrintStatement *statement) {
  tos_value_ = nullptr;
}

void IrtreeBuildVisitor::Visit(AssignmentList *assignment_list) {
  if (assignment_list->statements_.empty()) {
    tos_value_ = nullptr;
    return;
  }

  if (assignment_list->statements_.size() == 1) {
    tos_value_ = Accept(assignment_list->statements_[0]);
  } else {
    std::vector<IRT::Statement*> statements;
    statements.reserve(assignment_list->statements_.size());
//    size_t index = 0;
    for (auto statement: assignment_list->statements_) {
      auto stmt = Accept(statement);
      if (stmt) {
        statements.push_back(stmt->ToStatement());
      }
    }
    IRT::Statement* suffix = statements.back();

    for (int index = static_cast<int>(statements.size()) - 2; index >= 0; --index) {
      suffix = new IRT::SeqStatement(
        statements.at(index),
        suffix
      );
    }
    tos_value_ = new IRT::StatementWrapper(suffix);
  }
}

void IrtreeBuildVisitor::Visit(ScopeAssignmentList *list) {
  current_frame_->SetupScope();

  tos_value_ = Accept(list->statement_list);
  current_frame_->TearDownScope();
}

void IrtreeBuildVisitor::Visit(Program *program) {
  program->function_list_->Accept(this);
}


void IrtreeBuildVisitor::Visit(ParamList *param_list) {
  for (auto param: param_list->params_) {
    current_frame_->AddArgumentAddress(param);
  }

}
void IrtreeBuildVisitor::Visit(Function *function) {
  // build new frame
  current_frame_ = new IRT::FrameTranslator(function->name_);
  frame_translator_[function->name_] = current_frame_;

  function->param_list_->Accept(this);

  current_frame_->AddReturnAddress();

  auto statements_ir = Accept(function->statements_);

  if (statements_ir) {

    tos_value_ = new IRT::StatementWrapper(
        new IRT::SeqStatement(
            new IRT::LabelStatement(IRT::Label(function->name_)),
            statements_ir->ToStatement() // TODO: set return value 0 by default
        )
    );
  } else {
    // generating return 0
    tos_value_ = new IRT::StatementWrapper(
      new IRT::SeqStatement(
        new IRT::LabelStatement(IRT::Label(function->name_)),
        new IRT::MoveStatement(
            current_frame_->GetReturnValueAddress()->ToExpression(),
            new IRT::ConstExpression(0)
        )
      )
    );
  }

  method_trees_.emplace(function->name_, tos_value_->ToStatement());
}
void IrtreeBuildVisitor::Visit(FunctionCallExpression *statement) {
  IRT::ExpressionList* irt_expressions = new IRT::ExpressionList();

  for (auto it: statement->param_list_->params_) {
    irt_expressions->Add(Accept(it)->ToExpression());
  }

  tos_value_ = new IRT::ExpressionWrapper(
    new IRT::CallExpression(
        new IRT::NameExpression(IRT::Label(statement->name_)),
        irt_expressions
    )
  );

}
void IrtreeBuildVisitor::Visit(FunctionList *function_list) {
  for (auto function: function_list->functions_) {
    function->Accept(this);
  }

}
void IrtreeBuildVisitor::Visit(ParamValueList *value_list) {

}
void IrtreeBuildVisitor::Visit(ReturnStatement *return_statement) {
  auto return_expr = Accept(return_statement->return_expression_);
  tos_value_ = new IRT::StatementWrapper(
      new IRT::MoveStatement(
        current_frame_->GetReturnValueAddress()->ToExpression(),
        return_expr->ToExpression()
      )
  );
}


void IrtreeBuildVisitor::Visit(AndExpression *and_expression) {
  auto first_wrapper = Accept(and_expression->first);
  auto second_wrapper = Accept(and_expression->second);

  tos_value_ = new IRT::AndConditionalWrapper(
      first_wrapper,
      second_wrapper
  );
}

void IrtreeBuildVisitor::Visit(OrExpression *or_expression) {
  auto first_wrapper = Accept(or_expression->first);
  auto second_wrapper = Accept(or_expression->second);

  tos_value_ = new IRT::OrConditionalWrapper(
    first_wrapper,
    second_wrapper
  );
}

void IrtreeBuildVisitor::Visit(NotExpression *not_expression) {
  auto wrapper = Accept(not_expression->expression_);

  tos_value_ = new IRT::NegateConditionalWrapper(
      wrapper
  );
}
void IrtreeBuildVisitor::Visit(IfStatement *if_statement) {
  auto if_cond_expression = Accept(if_statement->bool_expression_);
  current_frame_->SetupScope();
  auto true_stmt = Accept(if_statement->true_statement_);
  current_frame_->TearDownScope();
  current_frame_->SetupScope();
  auto false_stmt = Accept(if_statement->false_statement_);
  current_frame_->TearDownScope();

  IRT::Label label_true;
  IRT::Label label_false;
  IRT::Label label_join;

  IRT::Statement* suffix = new IRT::LabelStatement(label_join);

  IRT::Label* result_true = &label_join;
  IRT::Label* result_false = &label_join;

  if (false_stmt) {
    result_false = &label_false;
    suffix = new IRT::SeqStatement(
        new IRT::LabelStatement(label_false),
        new IRT::SeqStatement(false_stmt->ToStatement(), suffix)
    );

    if (true_stmt) {
      suffix = new IRT::SeqStatement(
        new IRT::JumpStatement(label_join),
        suffix
      );
    }
  }

  if (true_stmt) {
    result_true = &label_true;
    suffix = new IRT::SeqStatement(
      new IRT::LabelStatement(label_true),
      new IRT::SeqStatement(true_stmt->ToStatement(), suffix)
    );
  }

  tos_value_ = new IRT::StatementWrapper(
    new IRT::SeqStatement(
      if_cond_expression->ToConditional(*result_true, *result_false),
      suffix
    )
  );

}
void IrtreeBuildVisitor::Visit(GtExpression *gt_expression) {
  tos_value_ = new IRT::RelativeConditionalWrapper(
      IRT::LogicOperatorType::GT,
      Accept(gt_expression->first)->ToExpression(),
      Accept(gt_expression->second)->ToExpression()
  );
}
void IrtreeBuildVisitor::Visit(LtExpression *lt_expression) {
  tos_value_ = new IRT::RelativeConditionalWrapper(
      IRT::LogicOperatorType::LT,
      Accept(lt_expression->first)->ToExpression(),
      Accept(lt_expression->second)->ToExpression()
  );
}

IrtreeBuildVisitor::IrtreeBuildVisitor(ScopeLayerTree *layer_tree): tree_(layer_tree) {
  // We don't need symbol table but you need with type system
  // Our functions return one type and operate with one type
}

IrtMapping IrtreeBuildVisitor::GetTrees() {
  return method_trees_;
}
