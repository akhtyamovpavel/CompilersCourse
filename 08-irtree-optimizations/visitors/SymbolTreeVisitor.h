#include "TemplateVisitor.h"

#include "symbol_table/Table.h"
#include <map>

#include "symbol_table/ScopeLayerTree.h"


class SymbolTreeVisitor: public Visitor {
 public:
  SymbolTreeVisitor();
  ~SymbolTreeVisitor() = default;
  void Visit(Function *function) override;
  void Visit(NumberExpression* expression) override;
  void Visit(AddExpression* expression) override;
  void Visit(SubstractExpression* expression) override;
  void Visit(MulExpression* expression) override;
  void Visit(DivExpression* expression) override;
  void Visit(IdentExpression* expression) override;
  void Visit(PrintStatement* statement) override;
  void Visit(Assignment* assignment) override;
  void Visit(VarDecl* var_decl) override;
  void Visit(StatementList* assignment_list) override;
  void Visit(ScopeAssignmentList* list) override;
  void Visit(Program* program) override;
  void Visit(ParamList* param_list) override;

  ScopeLayerTree GetRoot();
  void Visit(FunctionCallExpression *statement) override;

  std::unordered_map<Symbol, Function*> GetFunctions() const;

  void Visit(FunctionList *function_list) override;

  void Visit(ParamValueList *value_list) override;
  void Visit(ReturnStatement *return_statement) override;
  void Visit(AndExpression *and_expression) override;
  void Visit(OrExpression *or_expression) override;
  void Visit(NotExpression *not_expression) override;
  void Visit(IfStatement *if_statement) override;
  void Visit(GtExpression *gt_expression) override;
  void Visit(LtExpression *lt_expression) override;

 private:
    ScopeLayerTree tree_;
    ScopeLayer* current_layer_;
    std::unordered_map<Symbol, Function*> functions_;
};