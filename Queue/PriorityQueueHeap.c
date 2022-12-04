#include<stdio.h>
int N;
void pqinsert(int A[], int X)
{
    A[N]= X;
    int x=N;
    int y=(N-1)/2;
    while(x>0 && A[x]<A[y])
    {
        int temp=A[x];
        A[x]=A[y];
        A[y]= temp;
        x=y;
        y=(x-1)/2;
    }
    N=N+1;
}

void minheap(int A[], int i)
{
    while(2*i+1<=N-1)
    {
        int l= 2*i+1;
        int r= 2*i+1;
        int min=l;
        if(r<=N-1){
            if(A[r]<A[l]){
                min=r;
            }
        }
        if(A[min]<A[i]){
            int temp=A[min];
            A[min]= A[i];
            A[i]= temp;
        }
        else{
            break;
        }
        i=min;
    }
}

int pqdelete(int A[])
{
    int x=A[0];
    A[0]= A[N-1];
    N=N-1;
    minheap(A,0);
    return x;
}

int main(){
    int A[100];
    pqinsert(A,10);
    pqinsert(A,15);
    pqinsert(A,20);
    pqinsert(A,25);
    for(int i=0; i<N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("%d ",pqdelete(A));
    printf("\n");
    printf("%d ",pqdelete(A));

}