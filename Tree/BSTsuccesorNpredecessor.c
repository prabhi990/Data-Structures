#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
/******************************************************************************************************/
struct node{
	int data;
	struct node *left;
	struct node *right;
	struct node *father;
};
/******************************************************************************************************/
struct node *makenode(int x)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	p->father=NULL;
	return p;
}
/******************************************************************************************************/
int BSTinsert(struct node **t,int x)
{
	struct node *p,*q,*r;
	p=(*t);
	q=NULL;
	if((*t)==NULL){
		(*t)=makenode(x);
	}
	while(p!=NULL){
		q=p;
		if(x<p->data)
		    p=p->left;
		else
		    p=p->right;
	}
	r=makenode(x);
	if(x<q->data)
	    q->left=r;
	else
	    q->right=r;
	r->father=q;
}
/******************************************************************************************************/
struct node *BSTrecursive(struct node *t,int x)
{
	if(t!=NULL)
	    t=makenode(x);
	else{
		if(x<t->data)
		    t->left=BSTrecursive(t->left,x);
		else
		    t->right=BSTrecursive(t->right,x);
	}
	return t;
}
/******************************************************************************************************/
struct node *search(struct node *t,int key)
{
	struct node *p;
	p=t;
	while(p!=NULL){
		if(key==p->data)
		    return p;
		else if(key<p->data)
		    p=p->left;
		else
		    p=p->right;
	}
	return NULL;
}
/******************************************************************************************************/
int inorderTraverse(struct node *t)
{
	if(t!=NULL){
		inorderTraverse(t->left);
		printf("%d ",t->data);
		inorderTraverse(t->right);
	}
}
/******************************************************************************************************/
struct node *minimum(struct node *t)
{
	while(t->left!=NULL)
	    t=t->left;
	return t;
}
/******************************************************************************************************/
struct node *maximum(struct node *t)
{
	while(t->right!=NULL)
	    t=t->right;
	return t;	
}
/******************************************************************************************************/
struct node *BSTsuccesor(struct node *p)
{
	struct node *q;
	if(p->right!=NULL)
	    return minimum(p->right);
	else{
	    q=p->father;
	    while(q!=NULL && q->right==p){
		    p=q;
		    q=q->father;
	    }
	}
	return q;
}
/******************************************************************************************************/
struct node *BSTpredecessor(struct node *p)
{
	struct node *q;
	if(p->left!=NULL)
	    return maximum(p->left);
	else{
	    q=p->father;
	    while(q!=NULL && q->left==p){
		    p=q;
		    q=q->father;
	    }
	}
	return q;
}
/******************************************************************************************************/
int main()
{
	struct node *tree;
	tree=NULL;
	tree=makenode(200);
	BSTinsert(&tree,150);
	BSTinsert(&tree,160);
	BSTinsert(&tree,120);
	BSTinsert(&tree,180);
	BSTinsert(&tree,170);
	BSTinsert(&tree,140);
	BSTinsert(&tree,100);
	BSTinsert(&tree,70);
	BSTinsert(&tree,50);
	BSTinsert(&tree,60);
	BSTinsert(&tree,90);
	printf("inorderTraverse traverse : ");
	inorderTraverse(tree);
	printf("\n");
/************************************************************/
	struct node *x=maximum(tree);
	printf("maximum : %d",x->data);
	printf("\n");
/************************************************************/
	struct node *y=minimum(tree);
	printf("minimum : %d",y->data);
	printf("\n");
/************************************************************/
    int n;
	printf("enter the element of which you want to find succesor : ");
	scanf("%d",&n);
	struct node *p = search(tree,n);
	struct node *r=BSTsuccesor(p);
	printf("succesor of %d is %d",n,r->data);
	printf("\n");
/************************************************************/
    int m;
	printf("enter the element of which you want to find predecessor : ");
	scanf("%d",&m);
	struct node *w=search(tree,m);
	struct node *u=BSTpredecessor(w);
	printf("succesor of %d is %d",m,u->data);
}