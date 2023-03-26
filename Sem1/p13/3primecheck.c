#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void checkno(int n)
{
  int flag = 0;
    if (n == 0 || n == 1 || n==2 || n==3)
    printf("0");

  for (int i = 2; i <= n / 2; ++i) {

    if (n % i == 0) {
      printf("1");
      break;
    }
    else printf("0");
  }
  
}


int main()
{
  
    int number, f;
    scanf("%d", &number);

    checkno(number);
    return 0;
}