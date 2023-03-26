#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void PFactors( int num)
{
        int i = 2;
        if( num == 1 )
                return;
        while( num%i != 0 )
                i++;
        printf("%d ", i);
        PFactors(num/i);
}
int main(){
    int n;
    scanf("%d", &n);
    PFactors;
    return 0;
}
