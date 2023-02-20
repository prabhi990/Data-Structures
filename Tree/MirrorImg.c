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
void *mirrorimg(struct node *t)
{
    if (t == NULL)
        return NULL;
    else {
        struct node* temp;
        mirrorimg(t->left);
        mirrorimg(t->right);
        temp = t->left;
        t->left = t->right;
        t->right = temp;
	}
}
/******************************************************************************************************/
int main()
{
	struct node *tree;
	tree=NULL;
	tree=makenode(200);
	insert(&tree,150);
	insert(&tree,160);
	insert(&tree,120);
	insert(&tree,180);
	insert(&tree,170);
	insert(&tree,140);
	insert(&tree,100);
	insert(&tree,70);
	insert(&tree,50);
	insert(&tree,60);
	insert(&tree,90);
	printf("inorder : "); inorderTraverse(tree);
	printf("\n");
	printf("preorder : "); preorderTraverse(tree);
	printf("\n");
	printf("postorder : "); postorderTraverse(tree);
	printf("\n");
	mirrorimg(tree);
	printf("\n");
	printf("mirror img inorder : "); inorderTraverse(tree);
	printf("\n");
	printf("mirror img preorder : "); preorderTraverse(tree);
	printf("\n");
	printf("mirror img postorder : "); postorderTraverse(tree);
	printf("\n");
}
