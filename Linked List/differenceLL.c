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
int insertafter(struct node **start,int x)
{
    struct node *p,*r;
    p=getnode();
    p->info=x;
    r=(*start)->next;
    p->next=r;
    (*start)->next=p;
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
int insertend(struct node **start,int x)
{
    struct node *q,*p;
    q=(*start);
    if(q==NULL)
    {
        insertbegin(start,x);
    }
    else
    {
        while((q->next)!= NULL)
        {
            q=q->next;
        }
        p=getnode();
        p->info=x;
        p->next=NULL;
        q->next=p;
    }
    
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
int orderedinsert(struct node **strt, int x)
{
    struct node *p, *q;
    p=(*strt);
    q=NULL;
    while(p!=NULL && x>=p->info){
        q=p;
        p=p->next;
    }
    if (q==NULL){
        insertbegin(strt,x);
    }
    else{
        insertafter(&q,x);
    }
}
/************************************************************/
int differenceLL(struct node **start1,struct node **start2)
{
    struct node *p,*q,*start3;
    p=(*start1);
    q=(*start2);
    start3=NULL;
    while(p!=NULL && q!=NULL)
    {
        if((p->info)<(q->info))
        {
            insertend(&start3,p->info);
            p=p->next;
        }
        else if((p->info)>(q->info))
        {
            q=q->next;
        }
        else
        {
            q=q->next;
            p=p->next;
        }
    }
    while(p!=NULL)
    {
        insertend(&start3,p->info);
            p=p->next;
    }
    printf("differnce : ");
    traverse(start3);
}
/***************************************************/
int main()
{
    struct node *start1,*start2;
    start1=NULL;
    start2=NULL;
    int a[5]={10,5,2,15,17};
    int b[7]={12,5,3,6,2,4,11};
    for(int i=0;i<=4;i++)
    {
        orderedinsert(&start1,a[i]);
    }
    for(int i=0;i<=6;i++)
    {
        orderedinsert(&start2,b[i]);
    }
    traverse(start1);
    traverse(start2);
    differenceLL(&start1,&start2);
}