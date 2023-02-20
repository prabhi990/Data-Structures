#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
/******************************************************************************************************/
struct node{
	int data;
	struct node *left;
	struct node *right;
};
/******************************************************************************************************/
struct node *makenode(int x)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}
/******************************************************************************************************/
int BSTinsert(struct node **t,int x)
{
	struct node *p,*q;
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
	if(x<q->data)
	    q->left=makenode(x);
	else
	    q->right=makenode(x);
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
int minimum(struct node *t)
{
	while(t->left!=NULL)
	    t=t->left;
	return t->data;
}
/******************************************************************************************************/
int maximum(struct node *t)
{
	while(t->right!=NULL)
	    t=t->right;
	return t->data;	
}
/******************************************************************************************************/
int main()
{
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
	printf("inorderTraverse traverse : ");
	inorderTraverse(tree);
	printf("\n");
	printf("%d",maximum(tree));
	printf("\n");
	printf("%d",minimum(tree));
}