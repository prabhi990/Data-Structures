#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"mystack.h"
/*****************************************************/
char prcd(char a,char b){
    if(a=='^' || a=='*' || a=='/' || a=='%'){
        if(b=='^'){
            return FALSE;
        }
        else{
            return TRUE;
        }
    }
    else{
        if(b=='+' || b=='-'){
            return TRUE;
        }
        else{
            return FALSE;
        }
    }
}
/*****************************************************/
void infixtopost(char infix[]){
    int i=0,j=0;
    char postfix[20];
    char x,symbol;
    Initialize();
    while(infix[i]!='\0'){
        symbol=infix[i];
        i++;
        if(symbol>='a' && symbol<='z'|| symbol>='A' && symbol<='Z'|| symbol>=0 && symbol<=9){
            postfix[j]=symbol;
            j++;
        }
        else{
            while(!IsEmpty() && prcd(StackTop(),symbol)){
                  x=Pop();
                  postfix[j]=x;
                  j++;
            }
            Push(symbol);
        }
    }
    while(!IsEmpty()){
        x=Pop();
        postfix[j]=x;
        j++;
    }
    postfix[j]='\0';
    puts(postfix);
}
int main(){
    char infix[20];
    gets(infix);
    infixtopost(infix);
}