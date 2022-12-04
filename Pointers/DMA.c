#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *p;
    p = (int*)malloc(40);
    for(int i=0;i<10;i++){
        scanf("%d",(p+i));
    }
    for(int i=0;i<10;i++){
        printf("%d ",*(p+i));
    }
}