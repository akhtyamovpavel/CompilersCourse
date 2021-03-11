#include "Visitor.h"

#include <map>

class Interpreter : public Visitor {
 public:
    Interpreter();
    void Visit(NumberExpression* expression) override;
    void Visit(AddExpression* expression) override;
    void Visit(SubstractExpression* expression) override;
    void Visit(MulExpression* expression) override;
    void Visit(DivExpression* expression) override;
    void Visit(IdentExpression* expression) override;
    void Visit(Assignment* assignment) override;
    void Visit(StatementList* assignment_list) override;
    void Visit(Program* program) override;

    int GetResult(Program* program);

 private:
    std::map<std::string, int> variables_;
    bool is_tos_expression_;
    int tos_value_;

    void SetTosValue(int value);
    void UnsetTosValue();
    
};