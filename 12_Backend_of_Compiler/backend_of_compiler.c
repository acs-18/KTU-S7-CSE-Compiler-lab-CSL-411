#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    char icode[10][10],str[10],opr[10];
    int i=0;
    printf("\n Enter The Set Of Intermediate Code : \n");
    do
    {
        scanf("%s",icode[i]);
    }
    while(strcmp(icode[i++],"exit")!=0);
    printf("\n Target Code Generation : ");
    printf("\n");
    i=0;
    do
    {
        strcpy(str,icode[i]);
        switch(str[3])
        {
            case '+':
                strcpy(opr,"ADD");
            break;
            case '-':
                strcpy(opr,"SUB");
            break;
            case '*':
                strcpy(opr,"MUL");
            break;
            case '/':
                strcpy(opr,"DIV");
            break;
        }
        printf("\n\t MOV %c , R %d",str[2],i);
        printf("\n\t %s %c , R %d",opr,str[4],i);
        printf("\n\t MOV R %d , %c ",i,str[0]);
    }
    while(strcmp(icode[++i],"exit")!=0);
}