#include <iostream>
#include <vector>
using namespace std;
int dfs_visit(int i,vector<int> &visited,int e,vector<int>adjlist[]){
    visited[i]=1;
    cout<<i<<" ";
    e++;
    for(auto j: adjlist[i]){
        if(visited[j]==0){
            e = dfs_visit(j,visited,e,adjlist);
        }
    }
    return e;
}
vector<int> dfs(vector<int>adjlist[],int v,int &count){
    vector<int> visited(v);
    vector<int> ans;
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            count++;
            int e = 0;
            e = dfs_visit(i,visited,e,adjlist);
            ans.push_back(e);
        }
    }
    
    return ans;
}
int main(){
    int v,e;
	cout<<"no. of vertices : ";
	cin>>v;
	cout<<"no. of edges : ";
	cin>>e;
    vector<int>adjlist[v];
    for(int i=1;i<=e;i++){
        int a, b;
        cout << "Enter the end points of Edge "<< i << " ";
        cin >> a >> b;
        adjlist[a].push_back(b);
    }
    int count = 0;
    cout<<endl<<"DFS SEQUENCE IS : "<<endl;
    vector<int> elements = dfs(adjlist,v,count);
    cout<<endl;
    cout<<"Total Components in given Graph is: "<<count<<endl;
    cout<<"Total Elements in given Component is: ";
    for(int i=1;i<=elements.size();i++){
        cout<<i<<" : "<<elements[i-1]<<endl;
    }    
    return 0;
}