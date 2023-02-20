#include<iostream>
using namespace std;
struct sparse
{
	int row;
	int col;
	int data;
};
int w=0;
int main()
{
	int r,c;
	cout<<"enter the size of matrix : ";
	cin>>r>>c;
	int matrix[r][c];
	cout<<"enter the elements :"<<endl;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>matrix[i][j];
		}
	}
	cout<<endl;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	int size=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(matrix[i][j]!=0){
				size++;
			}
		}
	}
	struct sparse *s[size];

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(matrix[i][j]!=0){
				s[w]->row = i;
				s[w]->col = j;
				s[w]->data = matrix[i][j];
				w++;
			}
		}
	}
	for(int i=0;i<size;i++){
		cout<<s[i]->row<<" "<<s[i]->col<<" "<<s[i]->data<<endl;
	}
}