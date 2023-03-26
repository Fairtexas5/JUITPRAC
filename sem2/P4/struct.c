#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

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
    struct customer customers[MAX_CUSTOMERS];
    int num_customers;
    int i;

    printf("Enter the number of customers: ");
    scanf("%d", &num_customers);

    // Input customer records
    for (i = 0; i < num_customers; i++) {
        printf("\nCustomer #%d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", customers[i].name);
        printf("Street: ");
        scanf(" %[^\n]", customers[i].street);
        printf("City: ");
        scanf(" %[^\n]", customers[i].city);
        printf("Contact: ");
        scanf(" %[^\n]", customers[i].contact);
        printf("Account number: ");
        scanf("%d", &customers[i].account_number);
        printf("Account type: ");
        scanf(" %[^\n]", customers[i].account_type);
        printf("Old balance: ");
        scanf("%f", &customers[i].old_balance);
        printf("Current payment: ");
        scanf("%f", &customers[i].current_payment);
        printf("Payment date (mm/dd/yyyy): ");
        scanf("%d/%d/%d", &customers[i].payment_date.month, &customers[i].payment_date.day, &customers[i].payment_date.year);

        // Update new balance
        customers[i].new_balance = customers[i].old_balance - customers[i].current_payment;
    }

    // Display customer records with account status
    printf("\nCustomer Records:\n");
    for (i = 0; i < num_customers; i++) {
        printf("\nCustomer #%d:\n", i + 1);
        printf("Name: %s\n", customers[i].name);
        printf("Street: %s\n", customers[i].street);
        printf("City: %s\n", customers[i].city);
        printf("Contact: %s\n", customers[i].contact);
        printf("Account number: %d\n", customers[i].account_number);
        printf("Account type: %s\n", customers[i].account_type);
        printf("Old balance: %.2f\n", customers[i].old_balance);
        printf("Current payment: %.2f\n", customers[i].current_payment);
        printf("New balance: %.2f\n", customers[i].new_balance);

        // Determine account status
        if (customers[i].current_payment > 0 && customers[i].current_payment < 0.1 * customers[i].old_balance) {
            printf("Account status: OVERDUE\n");
        } else if (customers[i].new_balance > 0 && customers[i].current_payment == 0) {
            printf("Account status: DELINQUENT\n");
        } else {
            printf("Account status: CURRENT ACCOUNT\n");
        }
    }

    return 0;
}
/**/