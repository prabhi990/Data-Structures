#include<stdio.h>
#include<stdlib.h>
struct node
{
	char ch;
	int freq;
	struct node *left;
	struct node *right;
	struct node *next;
};
/********************************************************/
struct node *makenode()
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->ch=NULL;
	p->freq=NULL;
	p->left=NULL;
	p->right=NULL;
	p->next=NULL;
	return p;
}
/********************************************************/
int insertbegin(struct node **start,int x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=*start;
    *start=p;
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
EnQueue()
/*********************************************************/
int main()
{

}