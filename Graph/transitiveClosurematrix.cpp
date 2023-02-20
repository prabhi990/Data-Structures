#include<bits/stdc++.h>
using namespace std;
int main()
{
	int V,E;
	cout<<"enter no. of vertices and edges : ";
	cin>>V>>E;
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
	}
	cout<<endl;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<adjmatrix[i][j]<<" ";
		}
		cout<<endl;
	}

	int m[V][V],t[V][V];
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			m[i][j]=adjmatrix[i][j];
			t[i][j]=adjmatrix[i][j];
		}
	}

	for(int l=0;l<V;l++){
		for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                int sum=0;
                for(int k=0;k<V;k++){
                    m[i][j]=m[i][j]+(t[i][k]*adjmatrix[k][j]);
                }
            }
		}
	 	cout<<endl;
	 for(int i=0;i<V;i++){
	 	for(int j=0;j<V;j++){
	 		cout<<t[i][j]<<" ";
	 	}
	 	cout<<endl;
	 }

		for(int a=0;a<V;a++){
            for(int b=0;b<V;b++){
                m[a][b]=m[a][b]+t[a][b]; 
            }
	    }
		cout<<endl;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	}
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(m[i][j]!=0){
				m[i][j]==1;
			}
		}
	}
	cout<<endl;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}

}