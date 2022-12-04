#include<stdio.h>
void sdiff(int a[],int m,int b[],int n)
{
    int i=0,j=0,k=0;
    int c[m+n];
    while(i<m && j<n)
 {
 if(a[i]<b[j])
 {
 c[k]=a[i];
 i++;
 k++;
 }
 else if(a[i]>b[j])
 {
 i++;
 }
 else
 {
 i++;
 j++;
 }
 }
 while(i<m)
 {
 c[k]=a[i];
 i++;
 k++;
 }
 while(j<n)
 {
 c[k]=b[j];
 j++;
 k++;
 }
 printf("symmetric difference of set:\n");
 for(i=0;i<k;i++)
 {
 printf("%d ",c[i]);
 }
}

void main()
{
 int m,n;
 printf("Enter the no. of elements for array a and b:\n");
 scanf("%d%d",&m,&n);
 int a[m],b[n];
 printf("enter elements for a:\n");
 for(int l=0;l<m;l++)
 { scanf("%d",&a[l]); }
 printf("enter elements for b:\n");
 for(int p=0;p<n;p++)
 { scanf("%d",&b[p]); }
  sdiff(a,m,b,n);
}