grammar Expr;
prog:   (expr NEWLINE)* ;
expr:   left=expr op=('*'|'/') right=expr // MulExpression | DivExpression
    |   left=expr op=('+'|'-') right=expr // AddExpression | SubExpression
    |   value=INT // NumberExpression
    |   '(' exp=expr ')' // BraceExpression
    ;
NEWLINE : [\r\n]+ ;
INT     : [0-9]+ ;