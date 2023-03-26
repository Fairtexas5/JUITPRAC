#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void op(int a, int b){
    float sum, diff, mul, div;
    sum = a+b;
    printf("Sum = %g\n", sum);
    diff = a-b;
    printf("Difference = %g\n", diff);
    mul = a*b;
    printf("Multiplication = %g\n", mul);
    div = (float)a/(float)b;
    printf("Division = %g\n", div);
}
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    op(a, b);
    return 0;
}