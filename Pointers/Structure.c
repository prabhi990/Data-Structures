#include<stdio.h>
#include<stdlib.h>
/**********************************************************************************/
struct Student
{
    int Rollno;
    char Name[20];
    double prcnt;
};
/**********************************************************************************/
int output(struct Student *p,int n)
{
    for(int i=0;i<n;i++){
    printf("%d %s %lf",(p+i)->Rollno,(p+i)->Name,(p+i)->prcnt);
    }
}
/**********************************************************************************/
int input(struct Student *p,int n)
{
    for(int i=0;i<n;i++){
    scanf("%d%s%lf",&((p+i)->Rollno),(p+i)->Name,&((p+i)->prcnt));
    }
    output(p,n);
}
/**********************************************************************************/
void main()
{
    struct Student *p;
    int n;
    scanf("%d",&n);
    p = (struct Student*)malloc(n*sizeof(struct Student));
    input(p,n);
}