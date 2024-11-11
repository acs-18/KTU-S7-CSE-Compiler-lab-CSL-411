#include<stdio.h>
#include<string.h>
int z=0,len=0,i=0,j=0;
char buff[10],ac[20],stk[20],act[20];

void check()
{
    for(z=0;z<=len;z++)
        if(stk[z] == 'i' && stk[z+1] == 'd')
        {
            stk[z] = 'E';
            stk[z+1] = '\0';
            printf("\n $%s\t%s$\t REDUCE TO E",stk,buff);
            j++;
        }
    for(z=0;z<=len;z++)
        if(stk[z] == 'E' && stk[z+1] =='+' && stk[z+2]=='E')
        {
            stk[z]='E';
            stk[z+1]='\0';
            printf("\n$%s\t%s$\t REDUCE TO E ",stk,buff);
            i=i-2;
        }
    for(z=0;z<=len;z++)
        if(stk[z] == 'E' && stk[z+1] =='*' && stk[z+2]=='E')
        {
            stk[z]='E';
            stk[z+1]='\0';
            printf("\n$%s\t%s$\t REDUCE TO E ",stk,buff);
            i=i-2;
        }
    for(z=0;z<=len;z++)
        if(stk[z] == '()' && stk[z+1] =='E' && stk[z+2]==')')
        {
            stk[z]='E';
            stk[z+1]='\0';
            printf("\n$%s\t%s$\t REDUCE TO E ",stk,buff);
            i=i-2;
        }
}

int main()
{
    printf("Enter The Input String :\n");
    scanf("%s",buff);
    len=strlen(buff);
    printf("Stack \t Input \t\t Action \n");
    for(i=0;j<len;i++,j++)
    {
        if(buff[j] == 'i' && buff[j+1]== 'd')
        {
            stk[i]=buff[j];
            stk[i+1]=buff[j+1];
            stk[i+2]='\0';
            buff[j]=' ';
            buff[j+1]=' ';
            printf("\n $%s\t%s$\t SHIFT ->id",stk,buff);
            check();
        }
        else
        {
            stk[i]=buff[j];
            stk[i+1]='\0';
            buff[j]=' ';
            printf("\n $%s\t%s$\t SHIFT ->symbol %c",stk,buff,stk[i]);
            check();
        }
    }
}