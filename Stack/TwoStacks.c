#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0
int item[STACKSIZE];
int TOP1,TOP2;
/**********************************************/
void initialise1(){
    TOP1=-1;
}
/**********************************************/
void initialise2(){
    TOP2=10;
}
/**********************************************/
int isempty1(){
    if (TOP1==-1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
/**********************************************/
int isempty2(){
    if (TOP2==10){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
/**********************************************/
void push1(char x){
    if(TOP1==TOP2-1){
        printf("stack1 overflow");
        exit(1);
    }
    TOP1=TOP1+1;
    item[TOP1]=x;
}
/**********************************************/
void push2(char x){
    if(TOP2==TOP1+1){
        printf("stack2 overflow");
        exit(1);
    }
    TOP2=TOP2-1;
    item[TOP2]=x;
}
/**********************************************/
char pop1(){
    if (isempty1()){
        printf("stack1 underflow");
        exit(1);
    }
    char x=item[TOP1];
    TOP1=TOP1-1;
    return x;
}
/**********************************************/
char pop2(){
    if (isempty2()){
        printf("stack2 underflow");
        exit(1);
    }
    char x=item[TOP2];
    TOP2=TOP2+1;
    return x;
}
/**********************************************/
char stacktop1(){
    char x=item[TOP1];
    return x;
}
/**********************************************/
char stacktop2(){
    char x=item[TOP2];
    return x;
}
/**********************************************/
int main(){
    initialise1();
    initialise2();
    push1(2);
}