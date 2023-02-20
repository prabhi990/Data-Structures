#include<iostream>
#include<vector>
using namespace std;
int main()
{
/*	vector<pair<int,int>>v;
	v.push_back(make_pair(125,563));
	v.push_back(make_pair(45,53));
	v.push_back(make_pair(55,556));
	v.push_back(make_pair(325,561));

	cout<<v.size()<<" "; */

	vector<vector<int>>v(2);
	v[0].push_back(1);
	v[0].push_back(2);
	v[1].push_back(3);
    v[1].push_back(4);
	v[1].push_back(5);

	for(int i=0;i<2;i++){
		cout<<i<<" ";
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}

}