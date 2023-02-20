#include <stdio.h>
#include <stdlib.h>
# define TRUE 1
# define FALSE 0
/******************************************************************************************/
struct node *rear,*front;
/******************************************************************************************/
struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};
/******************************************************************************************/
struct node* makenode(int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->next=NULL;
    return p;
}
/******************************************************************************************/
void initialise(){
    rear=NULL;
    front=NULL;
}
/******************************************************************************************/
void enqueue(struct node *p){
    if(rear!=NULL){
        rear->next=p;

    }
    else{
        front=p;
    }
    rear=p;

}
/******************************************************************************************/
 struct node *dequeue(){
    struct node *p;
    p=front;
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
    return p;
}
/******************************************************************************************/
int isempty(){
    if(front==NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }

}
/******************************************************************************************/
void levelorder(struct node *t){
    struct node *p;
    initialise();
    enqueue(t);
    while(!isempty()){
        p=dequeue();
        printf("%d ",p->data);
        if(p->left!=NULL){
            enqueue(p->left);
        }
        if(p->right!=NULL){
            enqueue(p->right);
        }
    }
}
/******************************************************************************************/
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
/*****************************/
void PreorderTraversal(struct node *T){
    if(T!=NULL){
        printf("%d ",T->data);
        PreorderTraversal(T->left);
        PreorderTraversal(T->right);
    }
}
/*****************************/
void inorderTraversal(struct node *T){
    if(T!=NULL){
        inorderTraversal(T->left);
        printf("%d ",T->data);
        inorderTraversal(T->right);
    }
}
/*****************************/
void postorderTraversal(struct node *T){
    if(T!=NULL){
        postorderTraversal(T->left);
        postorderTraversal(T->right);
        printf("%d ",T->data);
    }
}
/*****************************/
int main(){
    struct node *root=NULL;
    int x;
    printf("enter data of root node\n");
    scanf("%d",&x);
    root=makenode(x);
    createtree(&root);
    PreorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");
    levelorder(root);
}