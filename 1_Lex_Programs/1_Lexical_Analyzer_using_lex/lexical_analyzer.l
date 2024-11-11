%{
#include <stdio.h>
#include <stdlib.h>
%}
identifier [a-zA-Z][a-zA-Z0-9]*
number [0-9]+
Literal \"[^\"\\]*(\\.[^\"\\]*)*\"
%%
int|printf|while|for|do|float|main|scanf|if|else|return { printf("\nKEYWORD: %s", yytext); }
#.* { printf("\nPREPROCESSOR DIRECTIVE: %s", yytext); }
{identifier} { printf("\nIDENTIFIER: %s", yytext); }
{number} { printf("\nNUMBER: %s", yytext); }
{Literal} { printf("\nLITERAL: %s", yytext); }
\<=|\>=|==|\<|\>|\+|\-|\*|\/|\^|&|&&|\||\|\| { printf("\nOPERATOR: %s", yytext); }
\{|\}|\(|\) { printf("\nPUNCTUATION: %s", yytext); }
;|, { printf("\nSEPARATOR: %s", yytext); }
\/\/[^\n]* { /* Single-line comment: do nothing */ }
\/\*[^*]*\*+([^/*][^*]*\*+)*\/ { /* Multi-line comment: do nothing */ }
[ \t\n]+ { /* Ignore whitespace */ }
%%
int main(int argc, char **argv)
{
FILE *file;
file = fopen("test.c", "r");
if (!file)
{
perror("Error opening file");
exit(EXIT_FAILURE);
}
yyin = file;
yylex();
fclose(file);
return 0;
}
int yywrap()
{
return 1;
}