#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int m=0,n,i,j,k;
char a[10][10],f[10];
void first(char c);
void follow(char c);

void first(char c)
{
    int k;
    if(!isupper(c))
    f[m++]=c;
    for(k=0;k<n;k++)
    {
        if(a[k][0]==c)
        {
            if(!islower(a[k][2]))
                f[m++]=a[k][2];
            else
                first(a[k][2]);
        }
    }
}

void follow(char c)
{
    if(a[0][0]==c)
        f[m++]='$';
    for(i=0;i<n;i++)
    {
        for(j=2;j<strlen(a[i]);j++)
        {
            if(a[i][j]==c)
            {
                if(a[i][j+1]!='\0')
                    first(a[i][j+1]);
                if(a[i][j+1] == '\0' && c!=a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}

int main()
{
    int z;
    char c;
    printf("Enter The No Of Productions : ");
    scanf("%d",&n);
    printf("Enter The productions :\n");
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        getchar();
    }
    do
    {
        printf("Enter The First And Follow To Be Found :\n");
        scanf("%c",&c);
        m=0;
        first(c);
        printf("First (%c) = {",c);
        for(i=0;i<m;i++)
            printf("%c",f[i]);
        printf("}\n");
        strcpy(f," ");
        m=0;
        follow(c);
        printf("Follow (%c) = {",c);
        for(i=0;i<m;i++)
            printf("%c",f[i]);
        printf("}\n");
        printf("\n Continue  (0/1) : ");
        scanf("%d",&z);
        getchar();
    }while(z==1);
    return 0;
}