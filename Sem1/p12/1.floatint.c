#include <stdio.h>
#include <math.h>
float mul(int ,float );
int main(){
   
    printf("Enter the one int and one float number: ");
    int x;
    float y;
    scanf("%d %f",&x,&y);
    float c= mul(x,y);
   printf("%f",c);
   return 0;
}
float mul(int a,float b){
    float result=a*b;
    return result;
}