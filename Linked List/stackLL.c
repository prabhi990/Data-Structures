#include<stdio.h>
#include<string.h>
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
        printf("%c ",p->info);
        p=p->next;
    }
    printf("\n");
}
/*********************************************************/
int insertafter(struct node **start,char x)
{
    struct node *p,*r;
    p=getnode();
    p->info=x;
    r=(*start)->next;
    p->next=r;
    (*start)->next=p;
}
/*********************************************************/
int insertbegin(struct node **start,char x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=*start;
    *start=p;
}
/*********************************************************/
int insertend(struct node **start,char x)
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
    char x=p->info;
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
    char x = q->info;
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
    char x=p->info;
    free(p);
    return x;
}
/*********************************************************/
void push(struct node *TOP,int x)
{
    insertbegin(&TOP,x);
}
/*********************************************************/
int pop(struct node *TOP)
{
    int x;
    x=deletebegin(&TOP);
    return x;
}
/********************************************************/
int isEmpty(struct node *TOP)
{
    if(TOP==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
/*********************************************************/
int main(){
    struct node *TOP;
    TOP = NULL;
    int x;
    push(TOP,100);
    push(TOP,200);
    push(TOP,300);
    push(TOP,400);
    traverse(TOP);
    pop(TOP);
    printf("\n%d",isEmpty(TOP));
}

