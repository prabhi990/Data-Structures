#include<stdio.h>
#include<stdlib.h>

int output(int *p,int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",*(p+i));
    }
}

int input(int *p,int n)
{
    for(int i=0;i<n;i++){
        scanf("%d",(p+i));
    }
    output(p,n);
}

void main()
{
    int n;
    printf("size of array : ");
    scanf("%d",&n);
    int *p;
    p = (int*)malloc(n*sizeof(int));
    input(p,n);
}