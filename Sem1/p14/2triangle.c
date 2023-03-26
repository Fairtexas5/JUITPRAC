#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void tri(int a, int b, int c, float *ar, int *peri){
    *peri = a + b + c;
    float s = (a+b+c)/2;
    *ar = sqrt(s*(s-a)*(s-b)*(s-c));
    printf("Perimeter = %d\n", *peri);
    printf("Area = %.2f", *ar);
}
int main(){
    int a, b, c, p;
    float A;
    scanf("%d%d%d", &a, &b, &c);
    tri(a, b, c, &A, &p);
}