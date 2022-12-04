#include<stdio.h>
void CountingSort(int a[],int n){
 int max=a[0];
 int ans[n];
 for(int i=1;i<=n;i++)
 {
 if(a[i]>max)
 {
 max=a[i];
 }
 }
 int k=max+1;
 int c[k];
 for(int i=0;i<k;i++){
 c[k]=0;
 }
 for(int i=0;i<n;i++)
 {
 c[a[i]]++;
 }
 for(int i=1;i<=k;i++)
 {
 c[i]=c[i]+c[i-1];
 }
 for(int i=n-1;i>=0;i--)
 {
 ans[c[a[i]]-1]=a[i];
 c[a[i]]--;
 }
 printf("sorted array: ");
 for(int i=0;i<n;i++)
 {
 printf("%d ",ans[i]);
 }
}
int main()
{
 int n;
 printf("enter the no. of elements: ");
 scanf("%d",&n);
 int a[n];
 printf("enter the elements: ");
 for(int i=0;i<n;i++){
 scanf("%d",&a[i]);
 }
 CountingSort(a,n);
return 0;
}
