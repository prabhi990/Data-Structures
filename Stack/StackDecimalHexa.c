#include <stdio.h>
#include<stdlib.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0

struct stack{
    int item[STACKSIZE];
    int TOP;
};

struct stack S;

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
    S.TOP= S.TOP+1;
    S.item[S.TOP]=x;
    
}

int Pop(){
    int x;
    if(IsEmpty()){
        printf("stack underdflows");
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

int main()
{
    int x;
    Initialize();
    int t;
    scanf("%d",&t);
    while(t!=0)
    {
       int a=t%16;
       Push(a);
       t/=16;
    }
    int pp;
    while(!IsEmpty(S))
    {
        pp=Pop(S.TOP);
        if(pp>9)
        {
           pp=pp+55;
           printf("%c",pp);
        }
        else
        {
           printf("%d",pp);
        }
       
        
        
    }
    
    return 0;
}