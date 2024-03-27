#include "ArithmeticsLexer.h"
#include "ArithmeticsParser.h"
#include "antlr4-runtime.h"
// #include "ArithmeticsBaseVisitor.h"

using namespace antlr4;

int main() {
  ANTLRInputStream input("2 + 2 * 2");
  ArithmeticsLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();
  for (auto token : tokens.getTokens()) {
    std::cout << token->toString() << std::endl;
  }

  ArithmeticsParser parser(&tokens);
  tree::ParseTree* tree = parser.expression();

  // auto visitor = new ArithmeticsBaseVisitor();

  // visitor->visit(tree);

  std::cout << tree->toStringTree(&parser) << std::endl << std::endl;

  return 0;
}