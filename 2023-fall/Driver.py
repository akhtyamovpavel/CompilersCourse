import sys
from antlr4 import *
from ExprLexer import ExprLexer
from ExprListener import ExprListener
from ExprParser import ExprParser


def main(argv):
    input_stream = FileStream('input.txt')
    lexer = ExprLexer(input_stream)
    stream = CommonTokenStream(lexer)
    parser = ExprParser(stream)
    tree = parser.prog()
    listener = ExprListener()
    walker = ParseTreeWalker()
    walker.walk(listener, tree)

if __name__ == '__main__':
    main(sys.argv)