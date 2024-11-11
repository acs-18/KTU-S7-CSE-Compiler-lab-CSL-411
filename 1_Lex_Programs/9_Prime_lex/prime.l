%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int num)
{
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0) return 0;
    return 1;
}
%}

%%

[0-9]+ { int num = atoi(yytext);
         printf("%d is %sprime.\n", num, is_prime(num) ? "" : "not ");
}

\n|. ; // Ignore newlines and other characters

%%

int main() {
    printf("Enter a number: ");
    yylex();
    return 0;
}