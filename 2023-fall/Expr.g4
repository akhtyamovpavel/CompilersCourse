grammar Expr;
prog:   (stmt NEWLINE)*
    ;
stmt: 'print' printexp=expr
    | IDENT ('=') assign=expr
    ;
expr:   left=expr op=('*'|'/') right=expr // MulExpression | DivExpression # left - .expr(0)
    |   left=expr op=('+'|'-') right=expr // AddExpression | SubExpression
    |   value=INT // NumberExpression
    |   '(' exp=expr ')' // BraceExpression
    ;
NEWLINE : [\r\n]+ ;
INT     : [0-9]+ ;
// PRINT   : 'print ' ;
IDENT   : [a-zA-Z]+ ;