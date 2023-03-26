#include <stdio.h>
#include <stdlib.h>

void absolute(int x){
    x = abs(x);
    printf("Value = %d", x);
}
int main(){
    int a;
    printf("Integer = ");
    scanf("%d", &a);
    absolute(a);
}