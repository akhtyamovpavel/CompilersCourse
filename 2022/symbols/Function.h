#include "BaseSymbol.h"
#include <unordered_map>
#include <vector>
#include "VariableSymbol.h"


namespace symbols {
  class Function: public BaseSymbol {
  public:
    Function();
    std::string return_type;
    std::vector<VariableSymbol> arguments;
  };
}
