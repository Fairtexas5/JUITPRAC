#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
    int n, i;
    printf("Enter integer: ");
    scanf("%d", &n);
    for (i =1; i<=n; i++){
        int mul = n*i;
        printf("%d * %d = %d\n", n, i, mul);

        mul = 0;
    }
    return 0;
}