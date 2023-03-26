#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("\nAfter Swapping: x = %d, y = %d", *x, *y);
}
 
int main(){
    int x, y;
    printf("Enter Value of x ");
    scanf("%d", &x);
    printf("\nEnter Value of y ");
    scanf("%d", &y);
    swap(&x, &y);
    return 0;
}