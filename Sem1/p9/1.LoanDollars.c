#include<stdio.h>

int main()
{
    float P, A, R, I, Unpaid, CI = 0.0, Amount;
    int c = 0;
    printf("Enter money borrowed from a bank : ");
    scanf("%f" , &P);
    
    printf("Enter amount to be repaid each month : ");
    scanf("%f" , &A);
    
    printf("Enter rate of interest per month : ");
    scanf("%f" , &R);
    while(P != 0)
    {
        c++;
        I = (P * R) / 100.0;
        CI = CI + I;
        Amount = P + I;
        Unpaid = Amount - A;
        printf("\nInterest = %g \n" , I);
        
        printf("Amount = %g \n" , Amount);
        
        printf("Balance Paid = %g \n" , A);
        
        printf("Remaining Balance = %g \n" , Unpaid);
        
        P = Unpaid;
        if(P < A)
        {
            I = (P * R) / 100.0;
            CI = CI + I;
            Amount = P + I;
            printf("\nLast Payment = %g \n\n" , Amount);
            P = 0;
        }
    }
    printf("Cumulative amount of interest = %g \n\n" , CI);
    
    printf("Number of monthly payments : %d \n" , c+1);
    
    return 0;

}