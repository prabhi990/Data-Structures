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
int mergingpoint(struct node *start1,struct node *start2)
{
	struct node *p,*q;
	p=(start1);
	q=(start2);
	int m=count(start1);
	int n=count(start2);
	if(m>n){
		for(int i=1;i<m-n;i++)
		p=p->next;
	}
	else if(n>m){
		for(int i=1;i<n-m;i++)
		q=q->next;
	}
	while((p->info)!=(q->info)){
		q=q->next;
		p=p->next;
	}
printf("%d %d",(p->info),(q->info));
	printf("merging point : %d",p->info);
}
/**********************************************************/
int main()
{
	struct node *start1,*start2;
	start1=NULL;
	start2=NULL;
	insertbegin(&start1,1);
	insertend(&start1,2);
	insertend(&start1,3);
	insertend(&start1,4);
	insertend(&start1,5);
	insertend(&start1,6);
	insertend(&start1,7);

	insertbegin(&start2,10);
	insertend(&start2,20);
	insertend(&start2,30);
	struct node *p,*q,*r;
	p=start1;
	while(p!=NULL){
		if(p->info==4){
			q=p->next;
			break;
		}
		p=p->next;
	}
	r=start2;
	while(r->next!=NULL){
		r=r->next;
	}
	r->next=q;
	traverse(start1);
	traverse(start2);
	mergingpoint(start1,start2);	
}