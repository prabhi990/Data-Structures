#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void jumpsearch(int a[],int n,int key)
{
 int step = sqrt(n);
 int low=0;
 int high=step;
 while(low < high){
 if(key>=a[low] && key<=a[high])
 {
 for(int i=low;i<=high;i++)
 {
 if(key==a[i])
 {
 printf("index of key is : %d",i);
 break;
 }
 }
 break;
 }
 else
 {
 low+=step;
 high+=step;
 }
 
} 
}
int main()
{
 int n;
 printf("enter no. of elements : ");
 scanf("%d",&n);
 int a[n];
 printf("enter the elements : ");
 for(int j=0;j<n;j++)
 {
 scanf("%d", &a[j]);
 }
 int key;
 printf("enter the key : ");
 scanf("%d",&key);
 jumpsearch(a,n,key);
return 0;
}