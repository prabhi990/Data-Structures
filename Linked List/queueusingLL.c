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
int insertbegin(struct node **start,int x)
{
    struct node *p;
    p=getnode();
    p->info=x;
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
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n");
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
struct node *swap(struct node *ptr1,struct node*ptr2)
{
    struct node *temp=ptr2->next;
    ptr2->next=ptr1;
    ptr1->next=temp;
    return ptr2;
}
/*********************************************************/
int sorting(struct node **start)
{
    int i,j,swapped,c = count(start);
    struct node **h;
    for(i=0;i<=count;i++)
    {
        h = start;
        swapped = 0;
        for(j=0;j<count-i-1;j++)
        {
            struct node *p1=*h;
            struct node *p2=p1->next;
            if(p1->info>p2->info)
            {
                *h=swap(p1,p2);
                swapped=1;
            }
            h=&(*h)->next;
        }
        if(swapped==0)
            break;
    }
}
/*********************************************************/
int insertafter(struct node *q,int x)
{
    struct node *p,*r;
    p=getnode();
    p->info=x;
    r=q->next;
    p->next=p;
    q->next=p;
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
void Enqueue(struct Node **FRONT,struct Node **REAR,int x){
    if((*REAR)==NULL){
        insertbegin((*REAR),x);
        (*FRONT)=(*REAR);
    }
    else{
        insertafter((*REAR),x);
        (*REAR) = (*REAR)->Next;
    }
}
int Dequeue(struct Node **FRONT,struct Node **REAR){
    int x;
    if((*FRONT)==NULL){
        printf("Deletion is not possible");
        exit(1);
    }
    else{
        x=deletebegin((*FRONT));
        if((*FRONT)==NULL) 
        *REAR=NULL;
    }
    return x;
}
int main(){
    struct Node *FRONT,*REAR;
    FRONT=NULL;
    REAR=NULL;
    int x;
    Enqueue(&FRONT,&REAR,10);
    Enqueue(&FRONT,&REAR,20);
    Enqueue(&FRONT,&REAR,30);
    Enqueue(&FRONT,&REAR,40);
    Enqueue(&FRONT,&REAR,50);
    Traverse(&FRONT);
    printf("\n%d",Dequeue(&FRONT,&REAR));
}
