#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>
#define TRUE 1;
#define FALSE 0;
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
int preorderTraverse(struct node *t)
{
	if(t!=NULL){
		printf("%d ",t->data);
		preorderTraverse(t->left);
		preorderTraverse(t->right);
	}
}
/******************************************************************************************************/

/******************************************************************************************************/
int postorderTraverse(struct node *t)
{
	if(t!=NULL){
		postorderTraverse(t->left);
		postorderTraverse(t->right);
		printf("%d ",t->data);
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
struct node *BSTpredecessor(struct node *t,struct node *p)
{
	struct node *q=t;
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
int Isleft(struct node *p)
{
	if(p->father->left==p){
	    return TRUE;
	}
	else{
	    return FALSE;
	}
}
/******************************************************************************************************/
int Isright(struct node *p)
{
	if(p->father->right==p){
	    return TRUE;
	}
	else{
	    return FALSE;
	}
}
/******************************************************************************************************/
struct node *siblings(struct node *p)
{
	if(Isleft(p)){
		return p->father->right;
	}
	else{
		return p->father->left;
	}
}
/******************************************************************************************************/
int BSTdelete(struct node *p)
{
	int x,y;
	struct node *q,*r,*l,*c;
	if(p->left==NULL && p->right==NULL){
		q=p->father;
		if(Isleft(p)){
			q->left=NULL;
		}
		else{
			q->right=NULL;
		}
		x=p->data;
		free(p);
		return x;
	}
	else if(p->left==NULL || p->right==NULL){
		q=p->father;
		if(p->left==NULL)
		c=p->right;
		else
		c=p->left;
		if(Isleft(p))
		q->left=c;
		else
		q->right=c;
		c->father=q;
		x=p->data;
		free(p);
		return x;
	}
	else{
		q=BSTsuccesor(p);
		x=BSTdelete(q);
		y=p->data;
		p->data=x;
		return y;
	}
}
/******************************************************************************************************/
int main()
{
	int key;
	struct node *tree;
	tree=NULL;
	tree=makenode(120);
	BSTinsert(&tree,100);
	BSTinsert(&tree,110);
	BSTinsert(&tree,200);
	BSTinsert(&tree,150);
	BSTinsert(&tree,80);
	BSTinsert(&tree,90);
	BSTinsert(&tree,60);
	inorderTraverse(tree);
	printf("\n");
	printf("enter the key : ");
	scanf("%d",&key);
	struct node *p=search(tree,key);
	BSTdelete(p);
	inorderTraverse(tree);
	printf("\n");
}