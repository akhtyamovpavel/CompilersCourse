import sys
from antlr4 import *
from ExprLexer import ExprLexer
from ExprParser import ExprParser
from ExprVisitor import ExprVisitor
from nodes.Program import Program


def main(argv):
    input_stream = FileStream('input.txt')
    lexer = ExprLexer(input_stream)
    stream = CommonTokenStream(lexer)
    parser = ExprParser(stream)
    tree = parser.prog()
    
    ast_tree: Program = ExprVisitor().visit(tree)
    print(ast_tree.expressions)

if __name__ == '__main__':
    main(sys.argv)