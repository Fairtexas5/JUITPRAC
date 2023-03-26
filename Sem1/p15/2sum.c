#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int addsum(int n) {
  if (n != 0)
    return n + addsum(n - 1);
  else
    return n;
}
int main(){
    int n =25;
    printf("%d", addsum(n));
    return 0;
}