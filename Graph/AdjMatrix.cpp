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
	int adjmatrix[V][V];
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			adjmatrix[i][j]=0;
		}
	}
	for(int i=1;i<=E;i++){
		int a,b;
		cout<<"enter the pts of edges "<<i<<" : ";
		cin>>a>>b;
		adjmatrix[a][b]=1;
		adjmatrix[b][a]=1;
	}
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<adjmatrix[i][j]<<" ";
		}
		cout<<endl;
	}
}