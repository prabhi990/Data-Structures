#include <stdio.h>

int main(void) {
  int a[4][5];
  int i=2,j=3,x;
  printf("%u\n",a[0]);
  printf("%u\n",&a[2][3]);
  x=(i-0)*(4-0+1)+j-0;
  printf("%d\n",x);
  printf("%u",a[0]+x);
  return 0;
}

