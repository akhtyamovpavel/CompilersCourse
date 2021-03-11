#include <include/visitors/Visitor.h>
template<typename T>
class TemplateVisitor : public Visitor {
 public:
  T Accept(BaseElement* element);
  void SetValue(T value);
 protected:
  T tos_value_;
};

struct PrimitiveTypeHolder {
  bool bool_value;
  float float_value;
  int int_value;
};


