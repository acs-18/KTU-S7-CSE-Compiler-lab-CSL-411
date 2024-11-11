#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void input();
void constant();
void output();
void change();

struct expr
{
    char op[2],op1[5],op2[5],res[5];
    int flag;
}arr[10];
int n;

int main()
{
    input();
    constant();
    output();
    printf("\n");

    return 0;
}

void input()
{
    int i;
    printf("\n\n Enter The Maximum No Of Expressions : ");
    scanf("%d",&n);
    printf("\n Enter The Input :\n");
    for(i=0;i<n;i++)
    {
        scanf("%s %s %s %s",arr[i].op,arr[i].op1,arr[i].op2,arr[i].res);
        arr[i].flag=0;
    }
}

void constant()
{
    int i;
    int op1,op2,res;
    char op,res1[10];
    for(i=0;i<n;i++)
    {
        if(isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0]) || strcmp(arr[i].op,"=")==0)
        {
            op1=atoi(arr[i].op1);
            op2=atoi(arr[i].op2);
            op=arr[i].op[0];
            switch(op)
            {
                case '+' :
                    res=op1+op2;
                break;
                case'-' :
                    res=op1-op2;
                break;
                case '*' :
                    res=op1*op2;
                break;
                case '/' :
                    res=op1/op2;
                break;
            }
            sprintf(res1,"%d",res);
            arr[i].flag=1;
            change(i,res1);
        }
    }
}

void output()
{
    int i=0;
    printf("\n Optimized Code Is : ");
    for(i=0;i<n;i++)
    {
        if(!arr[i].flag)
        {
            printf("\n%s %s %s %s",arr[i].op,arr[i].op1,arr[i].op2,arr[i].res);
        }
    }
}

void change(int p,char*res)
{
    int i;
    for(i=p+1;i<n;i++)
    {
        if(strcmp(arr[p].res,arr[i].op1)==0)
            strcpy(arr[i].op1,res);
        if(strcmp(arr[p].res,arr[i].op2)==0)
            strcpy(arr[i].op2,res);
    }
}