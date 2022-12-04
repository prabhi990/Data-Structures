#include<stdio.h>

int intersection_array(int a[],int m,int b[],int n)
{
     int i=0,j=0,k=0,c[20];
     while(i<m && j<n)
     {
          if(a[i]<b[j])
          {
               
               i++;
               
          }
          else if(a[i]>b[j])
          {
               
               j++;
          
          }
          else
          {
               c[k]=a[i];
               i++;
               j++;
               k++;
          }
     }
     
     for(i=0;i<k;i++)
     {
          printf("%d ",c[i]);
     }
     return 0;
}

void main()
{
     int a[10]={1,3,5,6,9,11,12,14,17,19};
     int b[7]={2,4,6,8,10,12,14};
     intersection_array(a,10,b,7);
}




