#include<stdio.h>
int main()
{
    int stock, quantity;
    char credit;

    printf("Enter the quantity of stock: ");
    scanf("%d", &stock);

    printf("Is credit ok? (y/n) :   ");
    scanf("\n%c", &credit);

    printf("Enter the quantity ordered: ");
    scanf("\n%d", &quantity);
    

    if (credit == 'y' || credit == 'Y'){
        if (quantity <=stock){
            printf ("Supply his requirements");
        }
        else{
            printf("Supply the available stock.\n Also intimate him about the date and on which balance the remaining supply will be shipped.");
        }
    }
    else 
    printf("You Motherfucker, If you do not clear your credit I will send Goku and Bakugo to your Fucking place.\n\"The above message should be sent to the buyer.\"");


return 0;
}