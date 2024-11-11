%{ 
	#include<stdio.h> 
	#include<string.h> 
	int a = 0, b=0, c=0, d=0, l=0; 
%} 
	

%% 
[a-z] {a++;l++;} 
[A-Z] {b++;l++;} 
[0-9] {c++;l++;} 
[$&+,:;@#|.-^*%] {d++;l++;} 
. ; 
%% 
	
int yywrap(void){} 
	
int main() 
{	 
	// The function that starts the analysis 
	yylex(); 
	if(a>0 && b>0 && c>0 && d>0 && l>=8) 
	printf("VALID\n"); 
	else
		printf("INVALID\n"); 
	return 0; 
} 
