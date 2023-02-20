#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define TRUE 1;
#define FALSE 0;
/****************************************************************/
struct node{
	int data;
	struct node *left;
	struct node *right;
};
/****************************************************************/
struct node *makenode(int x)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}
/****************************************************************/
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
/****************************************************************/
struct node *BSTrecursive(struct node *t,int x)
{
	if(t==NULL)
	    t=makenode(x);
	else{
		if(x<t->data)
		    t->left=BSTrecursive(t->left,x);
		else
		    t->right=BSTrecursive(t->right,x);
	}
	return t;
}
/***************************************************************/
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
/***************************************************************/
int preorderTraverse(struct node *t)
{
	if(t!=NULL){
		printf("%d ",t->data);
		preorderTraverse(t->left);
		preorderTraverse(t->right);
	}
}
/****************************************************************/
int inorderTraverse(struct node *t)
{
	if(t!=NULL){
		inorderTraverse(t->left);
		printf("%d ",t->data);
		inorderTraverse(t->right);
	}
}
/****************************************************************/
int postorderTraverse(struct node *t)
{
	if(t!=NULL){
		postorderTraverse(t->left);
		postorderTraverse(t->right);
		printf("%d ",t->data);
	}
}
/*****************************************************************/
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
/*****************************************************************/
int IsBST(struct node *t)
{
	if(t==NULL){ 
	    return 1;
	}
	else if(t->left==NULL && t->right==NULL){
	    return 1;
	}
	else{
		if(t->left!=NULL){
		    if(t->left->data > t->data)
			    return 0;
		}
		if(t->right!=NULL){
			 if(t->right->data < t->data)
			    return 0;
		}
		return IsBST(t->left) && IsBST(t->right);
	}
}
/****************************************************************/
int main()
{
	int root;
	struct node *tree;
	tree=NULL;
	printf("enter the root node : ");
	scanf("%d",&root);
	tree=makenode(root);
	createtree(&tree);
	printf("\n");
	inorderTraverse(tree);
	printf("\n");
	int x=IsBST(tree);
	if(x==1) printf("TRUE");
	else printf("FALSE");
}