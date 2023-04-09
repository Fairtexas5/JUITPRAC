#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_c 100

// Structure definition for payment date
struct date {
    int month;
    int day;
    int year;
};

// Structure definition for customer record
struct customer {
    char name[50];
    char street[50];
    char city[50];
    char contact[20];
    int account_number;
    char account_type[20];
    float old_balance;
    float current_payment;
    float new_balance;
    struct date payment_date;
};

int main() {
    struct customer c[MAX_c];
    int num_c;
    int i;

    printf("Enter the number of c: ");
    scanf("%d", &num_c);

    // Input customer records
    for (i = 0; i < num_c; i++) {
        printf("\nCustomer #%d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", c[i].name);
        printf("Street: ");
        scanf(" %[^\n]", c[i].street);
        printf("City: ");
        scanf(" %[^\n]", c[i].city);
        printf("Contact: ");
        scanf(" %[^\n]", c[i].contact);
        printf("Account number: ");
        scanf("%d", &c[i].account_number);
        printf("Account type: ");
        scanf(" %[^\n]", c[i].account_type);
        printf("Old balance: ");
        scanf("%f", &c[i].old_balance);
        printf("Current payment: ");
        scanf("%f", &c[i].current_payment);
        printf("Payment date (mm/dd/yyyy): ");
        scanf("%d/%d/%d", &c[i].payment_date.month, &c[i].payment_date.day, &c[i].payment_date.year);

        // Update new balance
        c[i].new_balance = c[i].old_balance - c[i].current_payment;
    }

    // Display customer records with account status
    printf("\nCustomer Records:\n");
    for (i = 0; i < num_c; i++) {
        printf("\nCustomer #%d:\n", i + 1);
        printf("Name: %s\n", c[i].name);
        printf("Street: %s\n", c[i].street);
        printf("City: %s\n", c[i].city);
        printf("Contact: %s\n", c[i].contact);
        printf("Account number: %d\n", c[i].account_number);
        printf("Account type: %s\n", c[i].account_type);
        printf("Old balance: %.2f\n", c[i].old_balance);
        printf("Current payment: %.2f\n", c[i].current_payment);
        printf("New balance: %.2f\n", c[i].new_balance);

        // Determine account status
        if (c[i].current_payment > 0 && c[i].current_payment < 0.1 * c[i].old_balance) {
            printf("Account status: OVERDUE\n");
        } else if (c[i].new_balance > 0 && c[i].current_payment == 0) {
            printf("Account status: DELINQUENT\n");
        } else {
            printf("Account status: CURRENT ACCOUNT\n");
        }
    }

    return 0;
}
/**/