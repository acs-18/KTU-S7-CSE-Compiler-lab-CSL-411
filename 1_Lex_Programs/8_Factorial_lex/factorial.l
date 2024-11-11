%{
#include <stdio.h>
#include <stdlib.h>

int factorial(int num)
{
    int result = 1;
    for (int i = 1; i <= num; i++)
        result *= i;
    return result;
}
%}

%%

[0-9]+ { 
    int num = atoi(yytext);
    printf("Factorial of %d is %d\n", num, factorial(num)); 
}
\n|.   ;

%%

int main() {
    yylex();
    return 0;
}