#include<stdio.h>
void prime(int x)
{
    int a;
    for(a=2;a<=x;a++)
    {
        if(x%a==0)
        {
            printf("%d, ",a);
            x = x/a;
            a--;
        }
    }
}

int main(void)
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    prime(num);
}

