grammar Arithmetics;

SPACES: [ \t]+ -> skip;

NUM: [0-9]|[1-9][0-9]+;

expression
    : '(' expression ')'
    | expression '*' expression
    | expression '/' expression
    | expression '-' expression
    | expression '+' expression
    | NUM
    ;
