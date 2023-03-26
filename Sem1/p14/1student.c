#include<stdio.h>
void func(int a, int b, int c, float *avg, float *per);
void main()
{
    int a, b, c;
    float avg, per;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    func(a, b, c, &avg, &per);

    printf("Average: %.2f", avg);
    printf("\nPercentage: %.2f%%", per);
}

void func(int a, int b, int c, float *avg, float *per)
{
    *avg = (a+b+c)/3.0;
    *per = ((a+b+c)/300.0)*100;
}