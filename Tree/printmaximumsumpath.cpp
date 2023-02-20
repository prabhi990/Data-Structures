#include<iostream>
#include<vector>
using namespace std;
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
int max=0;
void sumKpath(struct node *tree,vector<int>&path){
	if(tree==NULL)       
	return ;
      
    path.push_back(tree->data);
      
    sumKpath(tree->left,path);
    sumKpath(tree->right,path);

    int sum=0;
    for(int i=path.size()-1;i>=0;i--){
        sum+=path[i];
        if(sum>max){
			
		}
    }
    path.pop_back();
}
int main(){
	struct node *root;
	int x,K;
	cout<<"enter the root node : ";
    cin>>x;
	root=makenode(x);
	createtree(&root);
	vector<int>path;
	sumKpath(root,path);
}