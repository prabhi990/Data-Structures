#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *child;
	struct node *sib;
	struct node *left;
	struct node *right;
};
/***************************************************/
struct node *makenode(int x)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	p->child=NULL;
	p->left=NULL;
	p->right=NULL;
	p->sib=NULL;
	return p;
}
/***************************************************/
int preorderTraverse(struct node *t)
{
	if(t!=NULL){
		printf("%d ",t->data);
		preorderTraverse(t->left);
		preorderTraverse(t->right);
	}
}
/****************************************************/
int inorderTraverse(struct node *t)
{
	if(t!=NULL){
		inorderTraverse(t->left);
		printf("%d ",t->data);
		inorderTraverse(t->right);
	}
}
/****************************************************/
int postorderTraverse(struct node *t)
{
	if(t!=NULL){
		postorderTraverse(t->left);
		postorderTraverse(t->right);
		printf("%d ",t->data);
	}
}
/***************************************************/
int createtree(struct node **t)
{
	int choice,x;
	struct node *p;
	printf("child of %d exist ?(1/0) : ",(*t)->data);
	scanf("%d",&choice);
	if(choice==1){
		printf("Input data of child of %d : ",(*t)->data);
		scanf("%d",&x);
		p=makenode(x);
		(*t)->child=p;
		createtree(&p);
	}
	printf("sibling of %d exist ?(1/0) : ",(*t)->data);
	scanf("%d",&choice);
	if(choice==1){
		printf("Input data of sibling of %d : ",(*t)->data);
		scanf("%d",&x);
		p=makenode(x);
		(*t)->sib=p;
		createtree(&p);
	}
}
/***************************************************/
struct node *convertbtree(struct node *t)
{
	
}
/***************************************************/
int main()
{
	struct node *Gtree;
	Gtree=makenode(1);
	createtree(&Gtree);
	struct node *btree=convertbtree(Gtree);
    printf("\n");
	inorderTraverse(btree);
    printf("\n");
	preorderTraverse(btree);
	printf("\n");
	postorderTraverse(btree);
	printf("\n");
	// printf("\n");
	// printf("\n");
}

