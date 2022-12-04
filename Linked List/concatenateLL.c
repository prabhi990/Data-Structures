#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
/*********************************************************/
struct node *getnode()
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
/*********************************************************/
int insertend(struct node **start,int x)
{
    struct node *q,*p;
    q=*start;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    p=getnode();
    p->info=x;
    p->next=NULL;
    q->next=p;
}
/*********************************************************/
int insertbegin(struct node **start,int x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=*start;
    *start=p;
}
/*********************************************************/
int count(struct node *start)
{
    int flag=0;
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        flag++;
        p=p->next;
    }
    printf("no. of nodes : %d \n",flag);
}
/*********************************************************/
int traverse(struct node *start)
{
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n");
}
/*********************************************************/
int concatenate(struct node *start1,struct node *start2)
{
    struct node *p;
    p=start1;
    while(p->next != NULL)
    {
        p=p->next;
    }
    p->next = start2;
    traverse(start1);
}
/*********************************************************/
int main()
{
    struct node *start1,*start2;
    start1=NULL;
    start2=NULL;
    insertbegin(&start1,10);
    insertbegin(&start1,51);
    insertbegin(&start1,36);
    insertbegin(&start1,45);
    insertbegin(&start1,78);
    insertbegin(&start1,53);
    insertbegin(&start1,20);
    insertend(&start1,44);
    insertend(&start1,55);
    insertend(&start1,50);
    traverse(start1);
    insertbegin(&start2,10);
    insertbegin(&start2,51);
    insertbegin(&start2,36);
    insertbegin(&start2,45);
    insertbegin(&start2,78);
    insertbegin(&start2,53);
    insertbegin(&start2,20);
    insertend(&start2,44);
    insertend(&start2,55);
    insertend(&start2,50);
    traverse(start2);
    concatenate(start1,start2);
}