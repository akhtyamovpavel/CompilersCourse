#include "TemplateVisitor.h"

#include <map>


class Interpreter : public TemplateVisitor<int> {
 public:
    Interpreter();
    void Visit(NumberExpression* expression) override;
    void Visit(AddExpression* expression) override;
    void Visit(SubstractExpression* expression) override;
    void Visit(MulExpression* expression) override;
    void Visit(DivExpression* expression) override;
    void Visit(IdentExpression* expression) override;
    void Visit(Assignment* assignment) override;
    void Visit(PrintStatement* statement) override;
    void Visit(AssignmentList* assignment_list) override;
    void Visit(Program* program) override;

    int GetResult(Program* program);

 private:
    std::map<std::string, int> variables_;
    
};