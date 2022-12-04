#include <stdio.h>
#include <math.h>
int gcd(int a, int b){
if (a == b)
return a;
else {
if (a > b)
return gcd(a - b, b);
else
return gcd(a, b - a); }}
int main()
{ int a, b;
printf("Enter the numbers : \n");
scanf("%d %d", &a, &b);
printf("GCD of the numbers is : ");
printf("%d", gcd(a, b));
return 0;}