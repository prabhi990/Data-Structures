#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	char data;
	struct node *left;
	struct node *right;
	struct node *next;
};
/********************************************/
struct node* makenode(char x)
{
	struct node *p;
	p=(struct node*)malloc((sizeof(struct node)));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	p->next=NULL;
	return p;
}
/*******************************************/
void inorderTraverse(struct node *t)
{
	if(t!=NULL){
		inorderTraverse(t->left);
		printf("%c ",t->data);
		inorderTraverse(t->right);
	}
}
/*******************************************/
void preorderTraverse(struct node *t)
{
	if(t!=NULL){
		printf("%c ",t->data);
		preorderTraverse(t->left);
		preorderTraverse(t->right);
	}
}
/*******************************************/
void postorderTraverse(struct node *t)
{
	if(t!=NULL){
		postorderTraverse(t->left);
		postorderTraverse(t->right);
		printf("%c ",t->data);
	}
}
/*******************************************/
int prcd(char a,char b)
{
    if(a=='^' || a=='*' || a=='/' || a=='%')
	{
        if(b=='^')
            return 0;
        else
            return 1;
    }
    else{
		if(a=='+' || a=='-'){
            if(b=='+' || b=='-')
                return 1;
            else
                return 0;
		}
    }
}
/*******************************************/
struct node *BuildExpTree(char *exp)
{
	int i=0;
	char symb,op;
	struct node *x,*y,*p,*q;
	struct node *start=NULL;
	char opstk[20];
	int top=-1;
	while(exp[i]!='\0')
	{
		symb=exp[i];
		i++;
		if(symb>='a' && symb<='z' || symb>='A' && symb<='Z' || symb>='0' && symb<='9')
		{
			x=makenode(symb);
			x->next=start;
			start=x;
		}
		else
		{
			while(top!=-1 && prcd(opstk[top],symb))
			{
				op=opstk[top--];
				y=makenode(op);

				p=start;
				start=start->next;

				q=start;
				start=start->next;

				y->right=p;
				y->left=q;

				y->next=start;
				start=y;
			}
			opstk[++top]=symb;
		}
	}
	while(top!=-1)
	{
				op=opstk[top--];
				y=makenode(op);

				p=start;
				start=start->next;

				q=start;
				start=start->next;

				y->right=p;
				y->left=q;

				y->next=start;
				start=y;
	}
	return start;
}
/*******************************************/
int main()
{
	char expression[20];
	struct node *tree;
	printf("enter your expression : ");
	gets(expression);
	tree=BuildExpTree(expression);
	printf("\n");
	printf("preorder : "); preorderTraverse(tree);
	printf("\n");
	printf("inorder : "); inorderTraverse(tree);
	printf("\n");
	printf("postorder : "); postorderTraverse(tree);
	printf("\n");
	return 0;
}
