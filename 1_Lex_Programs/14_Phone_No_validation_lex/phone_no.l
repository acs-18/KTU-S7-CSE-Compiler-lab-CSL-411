%{
    #include<stdio.h>
%}

%%
[1-9][0-9] {9} {printf("\n Mobile Number Is Valid \n");}
.{printf("\n Not Valid ! \n);}
%%

int main()
{
    printf("Enter The Mobile Number : ");
    yylex();
    printf("\n");
    return 0;
}