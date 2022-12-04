#include<stdio.h>
void binary_search(int a[],int n,int key)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
        {
            printf("%d",key);
            break;
        }
        else if(key>a[mid])
        {
            low=mid+1;
            continue;
        }
        else if(key<a[mid])
        {
            high=mid-1;
            continue;
        }      
    }
    if(low>high)
    {
        printf("not present");
    }
    
}

void main()
{
    int n,k;
    printf("enter no. of elements in the array: ");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements\n");
    for(int i=0;i<n;i++)
    {
        printf("a[%d]: ",i);
        scanf("%d",&a[i]);
    }
    printf("enter the key: ");
    scanf("%d",&k);
    binary_search(a,n,k);
}