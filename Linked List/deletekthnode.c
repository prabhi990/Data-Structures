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
/****************************************************/
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
    int x = q->info;
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
int delkthnode(struct node *start,int k)
{
    struct node *p,*q;
    p=start;
    int i=1;
    while(i<=k)
    {
        
        if(p!=NULL){
            i++;
            p=p->next;
        }
        else{
            printf("void deletion");
            return 1;
        }
    }
    q=start;
    if(p!=NULL)
    {
        while(p->next != NULL)
        {
            q=q->next;
            p=p->next;
        }
        deleteafter(&q);
    }
    else
    {
        deletebegin(&start);
    }
    traverse(start);
}
/*********************************************************/
int main()
{
    struct node *start;
    start=NULL;
    insertend(&start,1);
    insertend(&start,2);
    insertend(&start,3);
    insertend(&start,4);
    insertend(&start,5);
    insertend(&start,6);
    insertend(&start,7);
    insertend(&start,8);
    insertend(&start,9);
    insertend(&start,10);
    insertend(&start,11);
    traverse(start);
    delkthnode(start,4);
}