#include <stdio.h>
#include <string.h>
void bubble_sort(int a[],int n){
 for(int i=0 ; i < n-1; i++ ){
 for(int j=0 ; j < n-1 ; j++){
 if (a[j]>a[j+1]){
 int temp = a[j];
 a[j] = a[j+1];
 a[j+1] = temp; } } }
 printf("Sorted array: ");
 for(int i=0;i<n;i++){
 printf("%d " , a[i]);}}
void main(){ int n;
 printf("enter no. of elements in the array: ");
 scanf("%d",&n);
 int a[n];
 printf("enter the elements\n");
 for(int i=0;i<n;i++)
{ scanf("%d",&a[i]); }
 bubble_sort(a,n);}
