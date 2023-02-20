#include<stdio.h>
#include<stdlib.h>
int MAX(int x,int y)
{
	if(x>y)
	    return x;
	else
	    return y;
}
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *makenode(int x){
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}
int height(struct node *t)
{
	if(t==NULL)
	    return 0;
	else if(t->left==NULL && t->right==NULL)
	    return 1;
	else
	    return MAX(height(t->left),height(t->right))+1;
}
void createtree(struct node **t)
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
int diameter(struct node *t){
	if(t==NULL)
	return 0;
	else{
		int d1=height(t->left)+height(t->right)+1;
		int d2=diameter(t->left);
		int d3=diameter(t->right);
		int M=MAX(d1,d2);
		return MAX(M,d3);
	}
}
int main(){
	struct node *root;
	int x;
	printf("enter the root node : ");
	scanf("%d",&x);
	root=makenode(x);
	createtree(&root);
	printf("%d",diameter(root));
}