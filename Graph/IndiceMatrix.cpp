#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int V,E;
	cout<<"no. of vertices : ";
	cin>>V;
	cout<<"no. of edges : ";
	cin>>E;
	int indmatrix[V][E]; 
	for(int i=0;i<V;i++){
		for(int j=1;j<=E;j++){
			indmatrix[i][j]=0;
		}
	}
	for(int i=1;i<=E;i++){
		int a,b;
		cout<<"enter the pts of edges "<<i<<" : ";
		cin>>a>>b;
		indmatrix[a][i]=1;
		indmatrix[b][i]=1;
	}
	for(int i=0;i<V;i++){
		for(int j=1;j<=E;j++){
			cout<<indmatrix[i][j]<<" ";
		}
		cout<<endl;
	}
}