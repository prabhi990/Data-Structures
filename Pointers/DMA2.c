#include<stdio.h>
#include<stdlib.h>
void main()
{
    char *p;
    p=(char*)malloc(8);
    for(int i=0;i<4;i++){
        scanf("%c",(p+i));
    }
    for(int i=0;i<4;i++){
        printf("%c ",*(p+i));
    }
}