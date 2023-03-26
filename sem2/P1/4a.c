#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int sum(int n){
    int i;
    if (n<=1)
    return n;

    else return(n+sum(n-2));
}
int main(void){
    int n;
    scanf("%d", &n);
    printf("%d",sum(n));
}