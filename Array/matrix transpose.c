#include<stdio.h>
void main()
{
   int r,c;
   printf("enter no. of rows and column for matrix \n");
   scanf("%d%d",&r,&c);

   int m[r][c],d[c][r];
   

   printf("enter elements for m\n");
   for(int i=0;i<=r-1;i++)
   {
    for(int j=0;j<=c-1;j++)
    {
        printf("m[%d][%d]: ",i,j);
        scanf("%d",&m[i][j]);
    }
   }

   for(int i=0;i<=r-1;i++)
   {
    for(int j=0;j<=c-1;j++)
    {
       d[i][j]=m[j][i];
    }
   }

   printf("Transpose of the matrix is;\n");
   for(int i=0;i<=c-1;i++)
   {
    for(int j=0;j<=r-1;j++)
    {
        printf("%d ",d[i][j]);
    }
    printf("\n");
   }

}



