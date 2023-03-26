#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void Large(int x, int y, int z){
    int lag;
    lag = x > y ? (x > z ? x : z) : (y > z ? y : z);
 
    printf("%d is the largest number.", lag);
}
int main(){
    int a, b, c;
    scanf("%d%d%d", &a ,&b ,&c);
    Large(a, b, c);
}