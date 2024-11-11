%{
#include<stdio.h>
int valid=1;
%}
%token letter num
%%
start :letter s ;
s: letter | num s |
;
%%
int yyerror()
{
valid=0;
printf("\nInvalid Identifier!\n");
return 0;
}
int main()
{
printf("\nEnter the expression:\n");
yyparse();
if(valid)
{
printf("\nValid Identifier!\n");
}
}