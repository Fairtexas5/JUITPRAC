#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int series(int n){
    int i, f, fact;
    int facto(int n){
        if (n>=1)
        return n*facto(n-1);
        else
        return 1;
    }
    if (n<=1)
    sum = n/(facto(n))+(n-1)/(facto(n-1));
    else return n;
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d",);
}