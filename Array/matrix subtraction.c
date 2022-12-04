#include<stdio.h>
void main()
{
   int r,c;
   printf("enter no. of rows and column for matrix 1 and 21\n");
   scanf("%d%d",&r,&c);
   int m1[r][c],m2[r][c],d[r][c];

   printf("enter elements for m1\n");
   for(int i=0;i<=r-1;i++)
   {
    for(int j=0;j<=c-1;j++)
    {
        printf("m1[%d][%d]: ",i,j);
        scanf("%d",&m1[i][j]);
    }
   }

   printf("enter elements for m2\n");
   for(int i=0;i<=r-1;i++)
   {
    for(int j=0;j<=c-1;j++)
    {
        printf("m2[%d][%d]: ",i,j);
        scanf("%d",&m2[i][j]);
    }
   }

   // Matrix addition
   for(int i=0;i<=r-1;i++)
   {
    for(int j=0;j<=c-1;j++)
    {
        d[i][j]=m1[i][j]-m2[i][j];
    }
   }

    printf("Subtracted matrix: \n");
    for(int i=0;i<=r-1;i++)
   {
    for(int j=0;j<=c-1;j++)
    {
        printf("%d ",d[i][j]);
    }
    printf("\n");
   }
}