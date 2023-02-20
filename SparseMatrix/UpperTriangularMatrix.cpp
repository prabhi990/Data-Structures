#include<iostream>
using namespace std;
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
	int size = (r*(r+1))/2;
	int array[size];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(matrix[i][j]!=0){
			    int loc = (j*(j+1))/2 + i+1;
			    array[loc-1]=matrix[i][j];
			}
		}
	}
	for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
}