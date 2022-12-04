#include<stdio.h>
#include<limits.h>
int partition(int a[],int low,int high){
 int temp;
 int mid=(low+high)/2;
 temp=a[low];
 a[low]=a[mid];
 a[mid]=temp;
 int i=low;
 int j=high+1;
 int pivot=a[low];
do{
 do{
 i++;
 }while(a[i]<pivot);
 do{
 j--;
 }while(a[j]>pivot);
 if(i<j) {
 temp=a[i];
 a[i]=a[j];
 a[j]=temp;
 }
 }while(i<j);
 temp=a[j];
 a[j]=a[low];
 a[low]=temp; 
 return j;
}
void medianQS(int a[],int low,int high){
 if(low<high) {
 int j;
 j=partition(a,low,high);
 medianQS(a,low,j-1);
 medianQS(a,j+1,high); }
}
int main(){
 int n;
 printf("enter size of array: ");
 scanf("%d",&n);
 int a[n+1];
 printf("enter elements of array: ");
 for(int i=0;i<n;i++){
 scanf("%d",&a[i]);}
 a[n+1]=INT_MAX;
 int low=0;
 int high=n;
 medianQS(a,low,high);
 for(int i=1;i<=n;i++){
 printf("%d",a[i]);
 printf(" ");}
 return 0;}