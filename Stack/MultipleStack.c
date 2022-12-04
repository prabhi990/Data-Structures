#include <stdio.h>
#include<stdlib.h>
#define n 12
#define m 3
#define TRUE 1
#define FALSE 0

struct stack
{
    int item[STACKSIZE];
    int TOP;
};

struct stack S;

void Initialize()
{
    S.TOP=-1;
}

int IsEmpty()
{
    if(S.TOP==-1)
        return TRUE;
    else
        return FALSE;
}

int Push(int x)
{
    if(S.TOP==STACKSIZE-1){
        printf("stack overflows");
        exit(1);
    }
    S.TOP= S.TOP+1;
    S.item[S.TOP]=x;
    return x;
}

int Pop()
{
    int x;
    if(IsEmpty()){
        printf("stack underflows");
        exit(1);
    }
     x= S.item[S.TOP];
    S.TOP= S.TOP-1;
    return x;
}

int StackTop()
{
    int x= S.item[S.TOP];
    return x;
}