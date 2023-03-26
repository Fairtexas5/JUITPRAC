#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int table(int n, int i){
    if(i>12)
        return 0;
    else{
        printf("%d * %d = %d\n",n,i,n*i);
        return table(n,++i);
    }
}
int main(void){
    int n, i=1;
    scanf("%d", &n);
    table(n, i);
}