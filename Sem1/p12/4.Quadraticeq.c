#include<stdio.h>   
#include<stdlib.h>  
#include<math.h>  
  
void Quadratic( int a, int b, int c)  
{  
   double D, r1, r2, real, imag;
   D = b * b - 4 * a * c;

    if (D > 0) {
        r1 = (-b + sqrt(D)) / (2 * a);
        r2 = (-b - sqrt(D)) / (2 * a);
        printf("r1 = %.2lf and r2 = %.2lf", r1, r2);
    }  
else if (D == 0) {
        r1 = r2 = -b / (2 * a);
        printf("r1 = r2 = %.2lf;", r1);
    } 
else {
        real = -b / (2 * a);
        imag = sqrt(-D) / (2 * a);
        printf("r1 = %.2lf+%.2lfi and r2 = %.2f-%.2fi", real, imag, real, imag);
    } 
}  
int main(void)  
{  
    int x, y, z;  
    printf("Enter the value of coefficient x, y and z: ");  
    scanf("%d %d %d", &x, &y, &z);  
    Quadratic(x, y, z);   
}