#include<iostream>
using namespace std;
int main()
{
 int n,key;
 cout<<"enter no. of elements: ";
 cin>>n;
 int a[n];
 cout<<"enter the elements: ";
 for(int i=0;i<n;i++){
 cin>>a[i]; }
 cout<<"enter the key element: ";
 cin>>key;
 for(int i=0;i<n;i++){
 if(a[i]==key){
 cout<<i+1<<" element is: "<<a[i]; }
 }
 return 0;
}