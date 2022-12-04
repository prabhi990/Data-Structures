#include <stdio.h>
int main()
{
  for(int i=69;i>=65;i--)
    {
      for(int j=69;j>=i;j--)
        {
          printf("%c",j);
        }
      printf("\n");
    }
  return 0;
}