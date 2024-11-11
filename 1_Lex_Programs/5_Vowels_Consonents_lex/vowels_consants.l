%{
int countv=0;
int countc=0;
%}
%%
[A,E,I,O,U,a,e,i,o,u] {countv++;}
. {countc++;}
\n {return 0;}
%%
int main(){
printf("\nEnter the string\n");
yylex();
printf("\nNumber of vowels in given input : %d\n",countv);
printf("\nNumber of consonants in given input : %d\n",countc);
return 0;
}