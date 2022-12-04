#include <stdio.h>
#include<stdlib.h>
#define STACKSIZE 10
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

int main()
{
    int x;
    Initialize();
    Push(100);
    Push(200);
    Push(300);
    Push(600);
    x= Pop();
    printf("%d",x);
    
    return 0;
}