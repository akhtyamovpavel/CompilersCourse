#include "BaseSymbol.h"
#include <unordered_map>
#include <vector>
#include "VariableSymbol.h"


class Function: public BaseSymbol {
 public:
  Function();
  std::string return_type;
  std::vector<VariableSymbol> arguments;
};
