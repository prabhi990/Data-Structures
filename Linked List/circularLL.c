#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int dat[1000];
struct node{
    int info;
    struct node*next;
};
/*****************************************************/
struct node*getnode(){
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
/*****************************************************/
void insbeg(struct node**cstart,int x){
    struct node*p;
    p=getnode();
    p->info=x;
    
    if((*cstart)!=NULL){
        p->next=(*cstart)->next;
        (*cstart)->next=p;
    }
    else{
        *cstart=p;
        (*cstart)->next=p;
    }
    
}
/*****************************************************/
void insend(struct node**cstart,int x){
    struct node*p;
    p=getnode();
    p->info=x;
    if((*cstart)!=NULL){
        p->next=(*cstart)->next;
        (*cstart)->next=p;
        *cstart=p;
    }
    else{
        *cstart=p;
        (*cstart)->next=p;
    }
}
/*****************************************************/
void insafter(struct node**q,int x){
    struct node*p;
    
    if(q==NULL){
        printf("void insertion");
    }
    else{
        p=getnode();
        p->info=x;
        p->next=(*q)->next;
        (*q)->next=p;
    }
    
}
/*****************************************************/
int delbeg(struct node**cstart){
    struct node*p;
    p=(*cstart)->next;
    (*cstart)->next=p->next;
    
    if((*cstart)->next==(*cstart)){
        *cstart=NULL;
    }
    int x=p->info;
    free(p);
    return x;
}
/*****************************************************/
int delend(struct node**cstart){
    struct node*p,*q;
    q=*cstart;
    p=(*cstart)->next;
    while(p!=*cstart){
        p=p->next;
    }
    p->next=(*cstart)->next;
    *cstart=p;
    int x=q->info;
    free(q);
    return x;
}
/*****************************************************/
int delafter(struct node **q){
    struct node*p;
    p=(*q)->next;
    (*q)->next=p->next;
    int x=p->info;
    free(p);
    return x;
}
/*****************************************************/
void traverse(struct node*cstart){
    struct node*p;
    p=cstart->next;
    
    while(p!=cstart){
        printf("%d ",p->info);
            p=p->next;
        
    }
    printf("%d \n",p->info);
}
/*****************************************************/
int concatenate(struct node *cstart1,struct node *cstart2)
{
    struct node *p,*q;
    p=cstart1->next;
    q=cstart2->next;
    cstart1->next=q;
    cstart2->next=p;
    traverse(cstart2);
}
/*****************************************************/
int SumExceptItself(struct node *cstart)
{
    int sum=0;
    struct node *q,*p = cstart->next;
    while(p!=cstart)
    {
        sum+=p->info;
        p=p->next;
    }
    sum=sum+p->info;
    q=cstart->next;
    while(q!=cstart)
    {
        q->info=sum-q->info;
        q=q->next;
    }
    q->info=sum-q->info;
    traverse(cstart);
}
/*****************************************************/
int maximum(struct node *cstart)
{
    struct node *p;
    p=cstart->next;
    int max=0;
    while(p!=cstart)
    {
        if((p->info)>max)
        {
            max=p->info;
        }
        p=p->next;
    }
    if(p->info>max)
    {
        max=p->info;
    }
    return max;
}
/*****************************************************/
int fib(int n)
{
    if(n==1){
        dat[n]=0;
    }
    else if(n==2){
        dat[n] = 1;
    }
    else if(dat[n]==0){
        dat[n] = fib(n-1)+fib(n-2);
    }
    return dat[n];   
}
/*****************************************************/
int RemoveFibNodes(struct node **cstart,int m)
{
    int arr[100];
    printf("max = %d\n",m);
    int DAT[m],i=0;
    for(i=0;i<m;i++){
        DAT[i]=0;
    }

    for(i=1;i<m;i++){
        arr[i]=fib(i);
    }

    for(i=1;i<m;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    for(i=1;i<m;i++){
        DAT[arr[i]]=1;
    }
    
    for(i=0;i<m;i++){
        printf("%d ",DAT[i]);
    }
    printf("\n");
    struct node *p,*q;
    p=(*cstart)->next;
    q=(*cstart);
    while(p!=(*cstart)){
        if(DAT[p->info]==1){
            delafter(&q);
        }
        p=p->next;
        q=q->next;
    }
    if(DAT[p->info]==1){
        delafter(&q);
    }

}
/*****************************************************/
int main()
{
    struct node*cstart;
    cstart=NULL;
    insbeg(&cstart,8);
    insbeg(&cstart,2);
    insbeg(&cstart,1);
    insbeg(&cstart,5);
    insbeg(&cstart,6);
    insbeg(&cstart,3);
    insbeg(&cstart,11);
    insbeg(&cstart,4);
    insbeg(&cstart,15);
    insbeg(&cstart,10);
    insbeg(&cstart,12);
    traverse(cstart);
//    SumExceptItself(cstart);
    int m=maximum(cstart);
    RemoveFibNodes(&cstart,m);
    traverse(cstart);
    return 0;
}