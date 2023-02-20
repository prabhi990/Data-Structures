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
int preorder(struct node *t)
{
	if(t!=NULL){
		printf("%d ",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
/******************************************************************************************************/
int inorder(struct node *t)
{
	if(t!=NULL){
		inorder(t->left);
		printf("%d ",t->data);
		inorder(t->right);
	}
}
/******************************************************************************************************/
int postorder(struct node *t)
{
	if(t!=NULL){
		postorder(t->left);
		postorder(t->right);
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
int Search(int inordr[],int start,int end,int top)
{
	for(int i=start;i<=end;i++){
		if(inordr[i]==top){
			return i;
		}
	}
	return -1;
}
/******************************************************************************************************/
int i=9;
struct node *BuildTree(int inordr[],int postordr[],int start,int end)
{
	if(start>end)
	return NULL;
	int top=postordr[i];
	i--;
	struct node *p=makenode(top);
	if(start==end)
	return p;
	int pos=Search(inordr,start,end,top);
	p->right=BuildTree(inordr,postordr,pos+1,end);
	p->left=BuildTree(inordr,postordr,start,pos-1);
	return p;
}
/******************************************************************************************************/
int main()
{
	int inordr[]={3,12,6,4,7,10,11,5,2,8};
	int postordr[]={3,6,7,4,12,11,8,2,5,10};
	struct node *tree = BuildTree(inordr,postordr,0,9);
	printf("inorder traverse : ");
	inorder(tree);
	printf("\n");
	printf("preorder traverse : ");
	preorder(tree);
	printf("\n");
	printf("postorder traverse : ");
	postorder(tree);
	return 0;
}