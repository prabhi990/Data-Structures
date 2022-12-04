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
void infixtopre(char infix[]){
    int i=0,j=0;
    char prefix[20];
    char x,symbol;
    Initialize();
    strrev(infix);
    while(infix[i]!='\0'){
        symbol=infix[i];
        i++;
        if(symbol>='a' && symbol<='z'|| symbol>='A' && symbol<='Z'|| symbol>=0 && symbol<=9){
            prefix[j]=symbol;
            j++;
        }
        else{
            while(!IsEmpty() && !prcd(symbol,StackTop())){
                  x=Pop();
                  prefix[j]=x;
                  j++;
            }
            Push(symbol);
        }
    }
    while(!IsEmpty()){
        x=Pop();
        prefix[j]=x;
        j++;
    }
    prefix[j]='\0';
    strrev(prefix);
    puts(prefix);
}
int main(){
    char infix[20];
    gets(infix);
    infixtopre(infix);
}