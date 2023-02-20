#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int MAX(int x,int y)
{
	if(x>y)
	    return x;
	else
	    return y;
}
/*************************************************/
struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
};
/*************************************************/
struct node *makenode(int x)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	p->height=0;
	return p;
}
/*************************************************/
struct node *leftrotate(struct node *x)
{
	struct node *y,*z;
	y=x->right;
	z=y->left;
	y->left=x;
	x->right=z;
	return y;
}
/*************************************************/
struct node *rightrotate(struct node *x)
{
	struct node *y,*z;
	y=x->left;
	z=y->right;
	y->right=x;
	x->left=z;
	return y;
}
/*************************************************/
struct node *LL(struct node *x)
{
	struct node *y;
	y=rightrotate(x);
	return y;
}
/*************************************************/
struct node *RR(struct node *x)
{
	struct node *y;
	y=leftrotate(x);
	return y;
}
/*************************************************/
struct node *LR(struct node *x)
{
	struct node *y,*z,*t;
	y=x->left;
	z=leftrotate(y);
	x->left=z;
	t=rightrotate(x);
	return t;
}
/*************************************************/
struct node *RL(struct node *x)
{
	struct node *y,*z,*t;
	y=x->right;
	z=rightrotate(y);
	x->right=z;
	t=leftrotate(x);
	return t;
}
/*************************************************/
int preorderTraverse(struct node *t)
{
	if(t!=NULL){
		printf("%d ",t->data);
		preorderTraverse(t->left);
		preorderTraverse(t->right);
	}
}
/*************************************************/
int inorderTraverse(struct node *t)
{
	if(t!=NULL){
		inorderTraverse(t->left);
		printf("%d ",t->data);
		inorderTraverse(t->right);
	}
}
/*************************************************/
int postorderTraverse(struct node *t)
{
	if(t!=NULL){
		postorderTraverse(t->left);
		postorderTraverse(t->right);
		printf("%d ",t->data);
	}
}
/*************************************************/
int Height(struct node *t)
{
	int hL,hR;
	if(t==NULL){
	return 0;
	}
	if(t->left==NULL){
	hL=0;
	}
	else{
	hL=1+t->left->height;
	}

	if(t->right==NULL){
	hR=0;
	}
	else{
	hR=1+t->right->height;
	}
	return MAX(hL,hR);
}
/*************************************************/
int balancefactor(struct node *t)
{
	int hL,hR;
	if(t==NULL){
	return 0;
	}
	if(t->left==NULL){
	hL=0;
	}
	else{
	hL=1+t->left->height;
	}
	
	if(t->right==NULL){
	hR=0;
	}
	else{
	hR=1+t->right->height;
	}
	return hL-hR;
}
/*************************************************/
struct node *AVLinsert(struct node **t,int x)
{
	if(*t==NULL)
	    *t=makenode(x);
	else
	{
		if(x<(*t)->data)
		{
		    (*t)->left=AVLinsert((&(*t)->left),x);
		    if(balancefactor(*t)==2)
		    {
			    if(x<(*t)->left->data)
			    (*t)=LL(*t);
			    else
			    (*t)=LR(*t);
		    }
	    }
	    else
	    {
		    (*t)->right=AVLinsert((&(*t)->right),x);
		    if(balancefactor(*t)==-2)
		    {
			    if(x>(*t)->right->data)
			        t=RR(*t);
			    else
			        t=RL(*t);
		    }
	    }
	}
	(*t)->height=Height(*t);
	return t;
}
/*************************************************/
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
/*************************************************/
int main()
{
	struct node *tree=NULL;
	tree=AVLinsert(&tree,10);
	tree=AVLinsert(&tree,20);
	tree=AVLinsert(&tree,30);
	tree=AVLinsert(&tree,40);
	tree=AVLinsert(&tree,50);
	tree=AVLinsert(&tree,25);
	// tree=AVLinsert(tree,9);
	// tree=AVLinsert(tree,6);
	// tree=AVLinsert(tree,5);
	// tree=AVLinsert(tree,20);
	inorderTraverse(tree);
	printf("\n");
	preorderTraverse(tree);
	printf("\n");
	postorderTraverse(tree);
	printf("\n");
	// struct node *tree1;
	// tree1=makenode(12);
	// //createtree(&tree1);
	// inorderTraverse(tree1);
	// printf("\n");
	// preorderTraverse(tree1);
	// printf("\n");
	// postorderTraverse(tree1);

}


