#include<stdio.h>
int c[100];
void mergearray(int a[],int low,int mid,int high){
 int i=low,j=mid+1,k=low;
 while(i<=mid && j<=high){
 if(a[i]<a[j]) {
 c[k]=a[i];
 i++;
 k++; }
 else {
 c[k]=a[j];
 j++;
 k++; }
 }
 while(i<=mid) {
 c[k]=a[i];
 i++;
 k++; }
 while(j<=high) {
 c[k]=a[j];
 j++;
 k++; }
 for(i=low;i<=high;i++) {
 a[i]=c[i]; }
}
void mergesort(int a[],int low,int high){
 if(low<high) {
 int mid=(low+high)/2;
 mergesort(a,low,mid);
 mergesort(a,mid+1,high);
 mergearray(a,low,mid,high); }
}
int main(){
 int n;
 printf("enter no. of elements for the array: ");
 scanf("%d",&n);
 int a[n];
 printf("enter the elements in the array: ");
 for(int i=0;i<n;i++) {
 scanf("%d",&a[i]);
 }
 int low=0;
 int high=n-1;
 mergesort(a,low,high);
 printf("Sorted Array: ");
 for(int i=0;i<n;i++){
 printf("%d",a[i]);
 printf(" "); }
 return 0;}
