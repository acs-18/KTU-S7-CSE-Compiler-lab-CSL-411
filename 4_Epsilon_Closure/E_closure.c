#include<stdio.h>
#include<string.h>
int arr[10][10],visited[10];
int n,i,s1,s2,j,k,t;
char trans;

void closure(int i)
{
    visited[i]=1;
    for(j=0;j<n;j++)
    {
        if(arr[i][j] == 1 && visited[j]!=1)
        {
            printf(" ,q%d",j);
            closure(j);
            closure(i);
        }
    }
}
void main()
{
    printf("Enter The Total No Of States : ");
    scanf("%d",&n);
    printf("Enter The Total No Of Transitions : ");
    scanf("%d",&t);
    printf("Enter The Transitions  :\n");
    for(i=0;i<t;i++)
    {
        scanf("%d %c %d",&s1,&trans,&s2);
        if(trans=='e')
        {
            arr[s1][s2]=1;
        }
        printf(" ");
    }
    printf("\n Epsilon Closure :\n");
    for(i=0;i<n;i++)
    {
        printf("\n State q%d : {q %d",i,i);
        for(int i=0;i<n;i++)
            visited[i]=0;
        closure(i);
        printf("}");
    }
    printf("\n");
}