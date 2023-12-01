grammar Expr;
SPACES
 : [ \t] -> skip
 ;
FUN: ('fun'|'fun2');
LET: 'let';
MAIN: 'main';
NEWLINE : [\r\n]+ ;
INT     : [0-9]+ ;
IDENT   : [a-zA-Z]+ ;


prog:  FUN MAIN '(' ')' '{' NEWLINE ((stmt NEWLINE)*) '}'
    ;
stmt: 'print' printexp=expr
    | let=LET var=IDENT
    | ident=IDENT ('=') assign=expr
    ;
expr:   left=expr op=('*'|'/') right=expr // MulExpression | DivExpression # left - .expr(0)
    |   left=expr op=('+'|'-') right=expr // AddExpression | SubExpression
    |   value=INT // NumberExpression
    |   '(' exp=expr ')' // BraceExpression
    |   ident=IDENT // IdentExpression
    ;
