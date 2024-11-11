#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char input[100];
int pos;

void E();
void E_prime();
int main()
{
    printf("Enter The Grammer :\n\n");
    printf("E->iE\n");
    printf("E-> +iE'|*iE'|e\n\n");
    printf("Enter The Expression :\n");
    scanf("%s",input);
    E();
    if(input[pos]=='\0')
    {
        printf("\n Parsing Successfull,String Accepted\n");
    }
    else
    {
        printf("\n String Rejected\n");
    }
    return 0;
}

void match(char token)
{
    if(input[pos]==token)
    {
        pos++;
    }
}

void E()
{
    match('i');
    E_prime();
}

void E_prime()
{
    if(input[pos]=='+')
    {
        match('+');
        match('i');
        E_prime();
    }
    if(input[pos]=='*')
    {
        match('*');
        match('i');
        E_prime();
    }
}