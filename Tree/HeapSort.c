#include<stdio.h>
void MaxHeapify(int a[],int i,int n)
{
	int l,m,r,temp;
	while(2*i<=n)
	{
		l=2*i;
		r=2*i+1;
		m=l;
		if(r<=n)
			if(a[r]>a[l])
				m=r;
		if(a[m]>a[i])
		{
			temp=a[m];
			a[m]=a[i];
			a[i]=temp;
		}
		else break;
		i=m;
	}
}
void BuildMaxHeap(int a[],int n)
{
	int i,j;
	for(i=n/2;i>=1;i--)
	    MaxHeapify(a,i,n);
}
void Heapsort(int a[],int n)
{
	int j,temp;
	BuildMaxHeap(a,n);
	for(j=n;j>=2;j--){
		temp=a[1];
		a[1]=a[j];
		a[j]=temp;
		MaxHeapify(a,1,j-1);
	}
}
int main()
{
	int arr[8]={-1,10,2,5,3,9,8,6};
	Heapsort(arr,7);
	for(int i=1;i<=7;i++)
	    printf("%d ",arr[i]);
}