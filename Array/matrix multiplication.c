#include<stdio.h>
void main()
{
   int r1,c1,r2,c2;
   printf("enter no. of rows and column for matrix 1\n");
   scanf("%d%d",&r1,&c1);
   printf("enter no. of rows and column for matrix 2\n");
   scanf("%d%d",&r2,&c2);
   int m1[r1][c1],m2[r2][c2],c[r1][c2];
   if(c1==r2)
   {
   printf("enter elements for m1\n");
   for(int i=0;i<=r1-1;i++)
   {
    for(int j=0;j<=c1-1;j++)
    {
        printf("m1[%d][%d]: ",i,j);
        scanf("%d",&m1[i][j]);
    }
   }

   printf("enter elements for m2\n");
   for(int i=0;i<=r2-1;i++)
   {
    for(int j=0;j<=c2-1;j++)
    {
        printf("m2[%d][%d]: ",i,j);
        scanf("%d",&m2[i][j]);
    }
   }

   // Matrix multiplication
   for(int i=0;i<=r1-1;i++)
   {
    for(int j=0;j<=c2-1;j++)
    {
        int sum=0;
        for(int k=0;k<=c1-1;k++)
        {
            sum=sum+m1[i][k]*m2[k][j];
        }
        c[i][j]=sum;
    }
   }

    printf("Multiplied matrix: \n");
    for(int i=0;i<=r1-1;i++)
   {
    for(int j=0;j<=c2-1;j++)
    {
        printf("%d ",c[i][j]);
    }
    printf("\n");
   }
   }
   else 
   printf("Wrong Order of Matrix");
}