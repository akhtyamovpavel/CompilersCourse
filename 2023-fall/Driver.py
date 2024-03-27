import sys
from antlr4 import *
from ExprLexer import ExprLexer
from ExprParser import ExprParser
# from ExprVisitor import ExprVisitor
from nodes.Program import Program
from ExprListener import ExprListener
# from visitors.InterpeterNewVisitor import InterpreterNewVisitor


def main(argv):
    input_stream = FileStream('input.txt')
    lexer = ExprLexer(input_stream)
    stream = CommonTokenStream(lexer)
    parser = ExprParser(stream)
    listener = ExprListener()
    parser.addParseListener(listener)
    tree = parser.prog()
    
    
    
    # ast_tree: Program = ExprVisitor().visit(tree)
    # print(ast_tree.expressions)

    # try:
    #     interpeter = InterpreterNewVisitor()

    #     # ast_tree.accept(interpeter)

    #     interpeter.visit_program(ast_tree)
    # except Exception as e:
    #     print(e, file=sys.stderr)
    #     sys.exit(2)

if __name__ == '__main__':
    main(sys.argv)