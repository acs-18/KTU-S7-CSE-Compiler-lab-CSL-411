%{
#include<stdio.h>
int flag=0;
%}
%token num;
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
ArithmaticExpression : E {
printf("\nResult = %d\n",$$);
return 0;
};
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|E'%'E {$$=$1%$3;}
|'('E')' {$$=$2;}
| num {$$=$1;}
;
%%
void main()
{
printf("\n Enter The Arithmatic Exprssion : ");
yyparse();
if(flag==0)
printf("Entered Arithmatic Expression is Valid \n");
}
void yyerror()
{
printf("Entered Arithmatic Expression is invalid\n\n");
flag=1;
}