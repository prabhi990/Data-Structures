#include<stdio.h>
#include<stdlib.h>
struct student
{
   int Rollno;
   char Name[20];
   double prcnt;
};

void main()
{
    struct student S;
    struct student *p;
    p = &S;
    for(int i=0;i<5;i++){
    scanf("%d%s%lf",&((p+i)->Rollno),(p+i)->Name,&((p+i)->prcnt));
    }
    for(int i=0;i<5;i++){
    printf("%d %s %lf",(p+i)->Rollno,(p+i)->Name,(p+i)->prcnt);
    }
}