%%
abc {printf("ABC");}
. {printf("%s",yytext);}
\n {return 0;}
%%
int main(){
printf("\nEnter the string\n");
yylex();
return 0;
}