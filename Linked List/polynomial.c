#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int info;
    int expo;
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
int insertbegin(struct node **start,int x,int y)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->expo=y;
    p->next=*start;
    *start=p;
}
/*********************************************************/
int countevenodd(struct node *start)
{
    int flag1=0,flag2=0;
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        if(p->info % 2==0)
        {
            flag1++;
        }
        else
        {
            flag2++;
        }
        p=p->next;
    }
    printf("no. of even nodes : %d \n",flag1);
    printf("no. of odd nodes : %d \n",flag2);
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
        printf("%dx^%d ",p->info,p->expo);
        p=p->next;
    }
    printf("\n");
}
/*********************************************************/
int insertend(struct node **start,int x,int y)
{
    struct node *q,*p;
    q=(*start);
    if(q==NULL)
    {
        insertbegin(start,x,y);
    }
    else
    {
        while((q->next)!= NULL)
        {
            q=q->next;
        }
        p=getnode();
        p->info=x;
        p->expo=y;
        p->next=NULL;
        q->next=p;
    }  
}
/*********************************************************/
int insertafter(struct node **q,int x,int y)
{
    struct node *p,*r;
    p=getnode();
    p->info=x;
    p->expo=y;
    r=(*q)->next;
    p->next=p;
    (*q)->next=p;
}
/*********************************************************/
int orderedinsert(struct node **strt, int x,int y)
{
    struct node *p, *q;
    p=(*strt);
    q=NULL;
    while(p!=NULL && y>=p->expo){
        q=p;
        p=p->next;
    }
    if (q==NULL){
        insertbegin(strt,x,y);
    }
    else{
        insertafter(&q,x,y);
    }
}
/*********************************************************/
int deletebegin(struct node **start)
{
    struct node *p;
    p=*start;
    (*start)=(*start)->next;
    int x=p->info;
    free(p);
    return  x;
}
/*********************************************************/
int deleteafter(struct node **p)
{
    struct node *q,*r;
    q=(*p)->next;
    r=q->next;
    (*p)->next=r;
    int x=q->info;
    free(q);
    return x;
}
/*********************************************************/
int deleteEnd(struct node **start)
{
    struct node *p,*q;
    p=*start;
    q=NULL;
    while(p->next != NULL)
    {
        q=p;
        p=p->next;
    }
    q->next=NULL;
    int x=p->info;
    free(p);
    return x;

}
/*********************************************************/
int polyadd(struct node *poly1,struct node *poly2)
{
    struct node *poly3 = NULL;
    struct node *p = poly1;
    struct node *q = poly2;
    while(p!=NULL && q!=NULL)
    {
        if(p->expo == q->expo)
        {
            insertend(&poly3,(p->info)+(q->info),p->expo);
            p=p->next;
            q=q->next;
        }
        else if(p->expo > q->expo)
        {
            insertend(&poly3,p->info,p->expo);
            p=p->next;
        }
        else
        {
            insertend(&poly3,q->info,q->expo);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        insertend(&poly3,p->info,p->expo);
        p=p->next;
    }
    while(q!=NULL)
    {
        insertend(&poly3,q->info,q->expo);
        q=q->next;
    }
    traverse(poly3);
}
/*********************************************************/
int polysub(struct node *poly1,struct node *poly2)
{
    struct node *q=poly2;
    while(q!=NULL)
    {
        q->info=-(q->info);
        q=q->next;
    }
    polyadd(poly1,poly2);
}
/*********************************************************/
int polymul(struct node *pol1,struct node *pol2)
{
    struct node *pol3 = NULL;
    struct node *q=pol2,*p;
    while(q!=NULL)
    {
        p=pol1;
        while(p!=NULL)
        {
            orderedinsert(&pol3,(p->info)*(q->info),(p->expo)+(q->expo));
            p=p->next;
        }
    }
    q=q->next;
    p=pol3;
    while(p->next!=NULL)
    {
        if(p->expo == p->next->expo)
        {
            p->info=(p->info)+(p->next->info);
            deleteafter(&p);
        }
        else
        {
            p=p->next;
        }
    }
    traverse(pol3);
}
/*********************************************************/
int main()
{
    struct node *poly1,*poly2;
    poly1=NULL;
    poly2=NULL;
    insertend(&poly1,8,5);
    insertend(&poly1,7,4);
    insertend(&poly1,5,3);
    insertend(&poly1,2,2);
    insertend(&poly1,6,1);
    insertend(&poly1,1,0);
    traverse(poly1);
    insertend(&poly2,9,5);
    insertend(&poly2,2,4);
    insertend(&poly2,6,3);
    insertend(&poly2,7,2);
    insertend(&poly2,3,1);
    insertend(&poly2,1,0);
    traverse(poly2);
    polyadd(poly1,poly2);
    polysub(poly1,poly2);
    polymul(poly1,poly2);
}