#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int sum=0;
/******************************************************************************************************/
int MAX(int x,int y)
{
	if(x>y)
	    return x;
	else
	    return y;
}
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
int insert(struct node **t,int x)
{
	struct node *p,*q;
	p=(*t);
	q=NULL;
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
int preorderTraverse(struct node *t)
{
	if(t!=NULL){
		printf("%d ",t->data);
		preorderTraverse(t->left);
		preorderTraverse(t->right);
	}
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
int postorderTraverse(struct node *t)
{
	if(t!=NULL){
		postorderTraverse(t->left);
		postorderTraverse(t->right);
		printf("%d ",t->data);
	}
}
/******************************************************************************************************/
int countnode(struct node *t)
{
	if(t==NULL)
	    return 0;
	else
	    return 1+countnode(t->left)+countnode(t->right);
}
/******************************************************************************************************/
int height(struct node *t)
{
	if(t==NULL)
	    return 0;
	else if(t->left==NULL && t->right==NULL)
	    return 0;
	else
	    return MAX(height(t->left),height(t->right))+1;
}
/******************************************************************************************************/
int countleafnode(struct node *t)
{
	if(t==NULL)
	    return 0;
	else if(t->left==NULL && t->right==NULL)
	    return 1;
	else
	    return countleafnode(t->left)+countleafnode(t->right);
}
/******************************************************************************************************/
int countN1node(struct node *t)
{
	if(t==NULL)
	    return 0;
	else if(t->left==NULL && t->right==NULL)
	    return 0;
	else if(t->left!=NULL && t->right!=NULL)
	    return countN1node(t->left)+countN1node(t->right);
	else
	    return 1+countN1node(t->left)+countN1node(t->right);
}
/******************************************************************************************************/
int countN2node(struct node *t)
{
	if(t==NULL)
	    return 0;
	else if(t->left==NULL && t->right==NULL)
	    return 0;
	else if(t->left!=NULL && t->right!=NULL)
	    return 1+countN1node(t->left)+countN1node(t->right);
	else
	    return countN1node(t->left)+countN1node(t->right);
}
/*****************************************************************************************************/
int createtree(struct node **t)
{
	int choice,x;
	struct node *p;
	printf("Left of %d exist ?(1/0) : ",(*t)->data);
	scanf("%d",&choice);
	if(choice==1){
		printf("Input data of left of %d : ",(*t)->data);
		scanf("%d",&x);
		p=makenode(x);
		(*t)->left=p;
		createtree(&p);
	}
	printf("Right of %d exist ?(1/0) : ",(*t)->data);
	scanf("%d",&choice);
	if(choice==1){
		printf("Input data of right of %d : ",(*t)->data);
		scanf("%d",&x);
		p=makenode(x);
		(*t)->right=p;
		createtree(&p);
	}
}
/*****************************************************************************************************/
char *strictlyBT(struct node *t)
{
    while(t->left!=NULL){
		if(countN1node(t->left)==0){
			strictlyBT(t->left);
		}
		t=t->left;
	}
	while(t->right!=NULL){
		if(countN1node(t->right)==0){
			strictlyBT(t->right);
		}
		t=t->right;
	}
	
}
/*****************************************************************************************************/
int main()
{
	struct node *tree;
	tree=makenode(10);
	createtree(&tree);
	strictlyBT(tree);
}