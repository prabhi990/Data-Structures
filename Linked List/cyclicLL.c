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
int cyclestart(struct node *start)
{
    struct node *t,*r;
    t=start;
    r=start->next;
    while(r!=NULL && r->next != NULL)
    {
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r)
            break;
    }
    t=start->next;
    while(r!=NULL && r->next != NULL)
    {
        t=t->next;
        r=r->next;
        if(t==r)
            break;
    }
    printf("starting : %d",r->info);
}
/*********************************************************/
int cyclelength(struct node *start)
{
    struct node *t,*r;
    t=start;
    r=start->next;
    while(r!=NULL && r->next != NULL)
    {
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r)
            break;
    }
    int c=0;
    do{
        c++;
        t=t->next;
    }while(t!=r);
    printf("cycle length = %d \n",c);
}
/*********************************************************/
int Iscyclic(struct node *start)
{
    struct node *t,*r;
    t=start;
    r=start->next;
    while(r!=NULL && r->next != NULL)
    {
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r)
            break;
    }
    if(t==r){
        printf("cyclic");
        printf("\n");
    }
    else{
        printf("non cyclic");
        printf("\n"); 
    }
}
/********************************************************/
int main()
{
    struct node *start1,*p,*q;
    start1=NULL;
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
    p=start1;
    while(p->next != NULL)
        p=p->next;
    
    q=start1;
    while(q->info != 78)
        q=q->next;
    
    p->next=q;
    Iscyclic(start1);
    cyclelength(start1);
    cyclestart(start1);
}