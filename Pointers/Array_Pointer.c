#include<stdio.h>
int main()
{
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    int *ptr;
    ptr = &A[0];
    for(int i=0;i<10;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d ",*(ptr+i));
    }
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d ",*(A+i));
    }
}