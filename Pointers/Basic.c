#include<stdio.h>
#include<stdlib.h>
void main()
{
    printf("%u ",sizeof(int));
    printf("%u ",sizeof(char));
    printf("%u ",sizeof(long int));
    printf("%u ",sizeof(float));
    printf("%u ",sizeof(double)); 

    int n,*p;
    scanf("%d",n);
    p=(int*)malloc(n);
}

