#include<stdio.h>
void ToH(int n,char s,char m,char d){
 if(n==1) {
 printf("%c-->%c\n",s,d);
 }
 else {
 ToH(n-1,s,d,m);
 printf("%c-->%c\n",s,m);
 ToH(n-1,m,s,d);
 }}
int main()
{ int n;
 char s,m,d;
 scanf("%d",&n);
 ToH(n,'s','m','d');
 return 0;}