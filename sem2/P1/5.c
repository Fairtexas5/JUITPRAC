#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int sum(int num)
{
    if (num==0)
        return 0;

    return (num%10+sum(num/10));
}
int main(void){
    int n;
    scanf("%d", &n);
    printf("%d",sum(n));
}