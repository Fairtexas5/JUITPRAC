#include<stdio.h>
int main()
{
    int count = 1, hours, overtime;
    float overpay;

    while(count<=10)
    {
        printf("Enter the working hours of employee no %d: ", count);
        scanf("%d", &hours);
        if(hours>40)
        {
            overtime = hours - 40;
            overpay = overtime * 12.00;
            printf("Employee No %d overtime pay is %.2f\n", count, overpay);
        }
        else
            printf("You have to work for more than 40 hours to get over time pay\n");

        count++;
    }
    return 0;
}