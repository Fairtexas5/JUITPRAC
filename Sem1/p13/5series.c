#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double Series(double x, int n)
{
  double sum = 1, term = 1, fct = 1, p = 1, multi = 1;
 
  for (int i = 1; i < n; i++)
  {
    fct = fct * multi * (multi + 1);
    p = p * x * x;
    multi += 2;
    sum = sum + (term * p) / fct;
  }
  return sum;
}
 
int main()
{
  double x;
  int n;
  printf("Enter the value of x: ");
  scanf("%lf", &x);
  printf("Enter the nuber of terms: ");
  scanf("%d", &n);
  printf("%.3f", Series(x, n));
  return 0;
}