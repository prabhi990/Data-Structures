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

struct stack *S;

void Initialize(struct stack *S)
{
    S->TOP=-1;
}

int IsEmpty(struct stack *S)
{
    if(S->TOP==-1)
        return TRUE;
    else
        return FALSE;
}

char Push(struct stack *S,char x)
{
    if(S->TOP==STACKSIZE-1){
        printf("stack overflows");
        exit(1);
    }
    S->TOP= S->TOP+1;
    S->item[S->TOP]=x;
    return x;
}

char Pop(struct stack *S)
{
    char x;
    if(IsEmpty(S)){
        printf("stack underflows");
        exit(1);
    }
     x= S->item[S->TOP];
    S->TOP= S->TOP-1;
    return x;
}

int StackTop(struct stack *S)
{
    int x= S->item[S->TOP];
    return x;
}

int main()
{
    char x;
    struct stack fs;
    Initialize(&fs);
    Push(&fs,'a');
    Push(&fs,'b');
    Push(&fs,'c');
    Push(&fs,'d');
    printf("%c",StackTop(&fs));
    printf("\n");
    Pop(&fs);
    printf("%c",fs);
    return 0;
}