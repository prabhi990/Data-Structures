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
int consvow(struct node *start)
{
    struct node *p,*q,*r;
    p=NULL;
    r=NULL;
    q=start;
    char x;
    while(q!=NULL)
    {
        if(q->info=='a'||q->info=='e'||q->info=='i'||q->info=='o'||q->info=='u'||q->info=='A'||q->info=='E'||q->info=='I'||q->info=='O'||q->info=='U')
        {
            q=q->next;
            if(p==NULL)
            {
                if(r!=NULL)
                {
                    x = deleteafter(&r);
                    insertbegin(&start,x);
                    p=start;
                }
                else
                {
                    x = deletebegin(&start);
                    insertbegin(&start,x);
                    p=start;
                    r=p;
                }
            }
            else
            {
                x=deleteafter(&r);
                insertafter(&p,x);
                p=p->next;
                r=p;
            }
        }
        else
        {
            r=q;
            q=q->next;
        }
    }
    traverse(start);
}
/*********************************************************/
int main()
{
    struct node *start;
    start=NULL;

    char *arr;
    arr =  malloc(1024*sizeof(char));
    gets(arr);
    int i=0;
    while(arr[i]!='\0'){
        insertend(&start,arr[i]);
        i++;
    } 
    consvow(start);
}