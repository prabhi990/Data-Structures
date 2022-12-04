#include<stdio.h>
/*****************************************/
void Traverse(int *ptr,int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",*(ptr+i));
    }
}
/*****************************************/
int main()
{
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    Traverse(A,10);
}