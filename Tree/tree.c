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
int sumofnodes(struct node *t)
{
	if(t!=NULL){
		sumofnodes(t->left);
		sum=sum+t->data;
		sumofnodes(t->right);
	}
	return sum;
}
/******************************************************************************************************/
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
/******************************************************************************************************/
int main()
{
	printf("\n");
	printf("***********************************************");
	printf("\n");
	struct node *tree;
	tree=NULL;
	tree=makenode(120);
	insert(&tree,100);
	insert(&tree,110);
	insert(&tree,200);
	insert(&tree,150);
	insert(&tree,80);
	insert(&tree,90);
	insert(&tree,60);
	printf("preorderTraverse traverse : ");
	preorderTraverse(tree);
	printf("\n");
	printf("inorderTraverse traverse : ");
	inorderTraverse(tree);
	printf("\n");
	printf("postorderTraverse traverse : ");
	postorderTraverse(tree);
	printf("\n");
	printf("no. of nodes : %d",countnode(tree));
	printf("\n");
	printf("height of tree : %d",height(tree));
	printf("\n");
	printf("no. of leaf nodes : %d",countleafnode(tree));
	printf("\n");
	printf("no. of nodes having 1 chidren : %d",countN1node(tree));
	printf("\n");
	printf("no. of nodes having 2 chidren : %d",countN2node(tree));
	printf("\n");
	printf("sum of nodes : %d",sumofnodes(tree));
	printf("\n");
	printf("***********************************************\n");


	struct node *tree1;
	tree1=NULL;
	tree1=makenode(100);
	int arr[5]={50,70,60,150,120};
	for(int i=0;i<5;i++){
		insert(&tree1,arr[i]);
	}
	printf("preorder traverse : ");
	preorderTraverse(tree1);
	printf("\n");
	printf("inorder traverse : ");
	inorderTraverse(tree1);
	printf("\n");
	printf("postorder traverse : ");
	postorderTraverse(tree1);
	printf("\n");
	printf("no. of nodes : %d",countnode(tree1));
	printf("\n");
	printf("height of tree1 : %d",height(tree1));
	printf("\n");
	printf("no. of leaf nodes : %d",countleafnode(tree1));
	printf("\n");
	printf("no. of nodes having 1 chidren : %d",countN1node(tree1));
	printf("\n");
	printf("no. of nodes having 2 chidren : %d",countN2node(tree1));
	printf("\n");
	printf("sum of nodes : %d",sumofnodes(tree1));
	printf("\n");
	printf("***********************************************\n");



	struct node *tree2;
	tree2=NULL;
	tree2=makenode(100);
	createtree(&tree2);
	printf("preorder traverse : ");
	preorderTraverse(tree2);
	printf("\n");
	printf("inorder traverse : ");
	inorderTraverse(tree2);
	printf("\n");
	printf("postorder traverse : ");
	postorderTraverse(tree2);
	printf("\n");
	printf("no. of nodes : %d",countnode(tree2));
	printf("\n");
	printf("height of tree2 : %d",height(tree2));
	printf("\n");
	printf("no. of leaf nodes : %d",countleafnode(tree2));
	printf("\n");
	printf("no. of nodes having 1 chidren : %d",countN1node(tree2));
	printf("\n");
	printf("no. of nodes having 2 chidren : %d",countN2node(tree2));
	printf("\n");
	printf("sum of nodes : %d",sumofnodes(tree2));
	printf("\n");
	printf("***********************************************\n");
	return 0;
}