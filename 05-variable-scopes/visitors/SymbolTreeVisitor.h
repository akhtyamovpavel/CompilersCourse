#include "TemplateVisitor.h"

#include "symbol_table/Table.h"
#include <map>

#include "symbol_table/ScopeLayerTree.h"


class SymbolTreeVisitor: public Visitor {
 public:
    SymbolTreeVisitor();
    ~SymbolTreeVisitor() = default;
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

    ScopeLayer* GetRoot();
 private:
    ScopeLayerTree tree_;
    ScopeLayer* current_layer_;
};