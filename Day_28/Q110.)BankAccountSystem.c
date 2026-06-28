#include <stdio.h>
#include <string.h>

// Structure to hold bank account details
struct BankAccount {
    int accountNumber;
    char name[100];
    float balance;
};

// Function prototypes
void createAccount(struct BankAccount *account);
void deposit(struct BankAccount *account);
void withdraw(struct BankAccount *account);
void checkBalance(struct BankAccount account);

int main() {
    struct BankAccount acc;
    int choice;
    acc.accountNumber = 0; // Flag to check if account exists

    printf("=== Welcome to the Banking System ===\n");

    do {
        printf("\n--- Menu ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&acc);
                break;
            case 2:
                if (acc.accountNumber == 0)
                    printf("Please create an account first!\n");
                else
                    deposit(&acc);
                break;
            case 3:
                if (acc.accountNumber == 0)
                    printf("Please create an account first!\n");
                else
                    withdraw(&acc);
                break;
            case 4:
                if (acc.accountNumber == 0)
                    printf("Please create an account first!\n");
                else
                    checkBalance(acc);
                break;
            case 5:
                printf("Thank you for using our Banking System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to create a new account
void createAccount(struct BankAccount *account) {
    printf("\nEnter Account Number: ");
    scanf("%d", &account->accountNumber);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", account->name); // Reads string with spaces
    account->balance = 0.0;
    
    printf("\nAccount successfully created for %s!\n", account->name);
}

// Function to deposit money
void deposit(struct BankAccount *account) {
    float amount;
    printf("\nEnter amount to deposit: $");
    scanf("%f", &amount);

    if (amount > 0) {
        account->balance += amount;
        printf("Successfully deposited $%.2f. New balance: $%.2f\n", amount, account->balance);
    } else {
        printf("Invalid amount. Deposit must be greater than 0.\n");
    }
}

// Function to withdraw money
void withdraw(struct BankAccount *account) {
    float amount;
    printf("\nEnter amount to withdraw: $");
    scanf("%f", &amount);

    if (amount > 0) {
        if (amount <= account->balance) {
            account->balance -= amount;
            printf("Successfully withdrawn $%.2f. New balance: $%.2f\n", amount, account->balance);
        } else {
            printf("Insufficient funds! Your current balance is $%.2f\n", account->balance);
        }
    } else {
        printf("Invalid amount. Withdrawal must be greater than 0.\n");
    }
}

// Function to check current balance
void checkBalance(struct BankAccount account) {
    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", account.accountNumber);
    printf("Holder Name: %s\n", account.name);
    printf("Current Balance: $%.2f\n", account.balance);
}