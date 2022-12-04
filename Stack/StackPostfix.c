#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0

    struct Stack{
    int item[STACKSIZE];
    int TOP;
};

struct Stack S;

void Initialize(){
    S.TOP=-1;
}

int IsEmpty(){
    if(S.TOP==-1)
        return TRUE;
    else
        return FALSE;
}

int Push(int x){
    if(S.TOP==STACKSIZE-1){
        printf("stack overflows");
        exit(1);
    }
    S.TOP = S.TOP+1;
    
    S.item[S.TOP]=x;
    return x;
}

int Pop(){
    int x;
    if(IsEmpty()){
        printf("stack underflows");
        exit(1);
    }
     x= S.item[S.TOP];
    S.TOP= S.TOP-1;
    return x;
    
}
int StackTop(){
    int x= S.item[S.TOP];
    return x;
}

int Evaluate(int a,int b,int symbol)
{
    switch (symbol)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        default : return pow(a,b);
    }
}

int main()
{
    
    int x,i=0;
    char postfix[20];
    char symbol;
    Initialize();
    scanf("%c",postfix);
    while(postfix[i] != '\0')
    {
        symbol=postfix[i];
        if(symbol>='0' && symbol<='9')
        {
            Push(symbol-48);
        }
        else
        {
            int b=Pop();
            int a=Pop();
            int value=Evaluate(a,b,symbol);
            Push(value);
        }
        i++;
    }
    x=Pop();
    printf("%d",x);
    return 0;
}