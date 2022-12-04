#include<stdio.h>
#include<stdlib.h>
int N=0;
int ArrayDelete(int A[],int i)
{
    for(int j=i+1;j<=N-1;j++)
    {
        A[j-1]=A[j];
    }
    N--;
}

int PQDelete(int A[])
{
    int x=A[0];
    ArrayDelete(A,0);
}

int ArrayInsert(int A[],int i,int x)
{
    for(int j=N-1;j>=i;j--)
    {
        A[j+1]=A[j];
    }
    A[i]=x;
    N++;
}

int PQInsert(int A[],int x)
{
    int i=0;
    while(i<N && x>=A[i])
    {
        i++;
    }
    ArrayInsert(A,i,x);
}

int main()
{
    int A[100];
    PQInsert(A,10);
    PQInsert(A,20);
    PQInsert(A,5);
    PQInsert(A,25);
    PQInsert(A,30);
    PQInsert(A,15);
    PQInsert(A,40);
    for(int i=0; i<N; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
} 