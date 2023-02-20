#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adjlist(1000);
vector<int>visited(1000,0);
void BFS(int V)
{
	int x;
	queue<int>Q;
	Q.push(0);
	visited[0]=1;
	cout<<"order of BFS : ";
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		for(int j=0;j<adjlist[x].size();j++){
			if(visited[adjlist[x][j]]==0){
				Q.push(adjlist[x][j]);
				visited[adjlist[x][j]]=1;
			}
		}
		cout<<x<<" ";
	}
}
int main()
{
	int V,E;
	cout<<"no. of vertices : ";
	cin>>V;
	cout<<"no. of edges : ";
	cin>>E;
	for(int i=1;i<=E;i++){
		int a,b;
		cout<<"enter the end points of edge "<<i<<" : ";
		cin>>a>>b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	for(int i=0;i<V;i++){
		cout<<i<<" : ";
		for(int j=0;j<adjlist[i].size();j++){
			cout<<adjlist[i][j]<<" ";
		}
		cout<<endl;
	}
	BFS(V);
}