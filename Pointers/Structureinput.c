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
    scanf("%d%s%lf",&(p->Rollno),p->Name,&(p->prcnt));
    printf("%d %s %lf",p->Rollno,p->Name,p->prcnt);
}