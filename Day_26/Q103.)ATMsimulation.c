#include <stdio.h>
#include <stdbool.h>

// Function declarations
void displayMenu();
void checkBalance(float balance);
float depositMoney(float balance);
float withdrawMoney(float balance);

int main() {
    // Initializing variables
    int defaultPin = 1234;
    int enteredPin;
    int pinAttempts = 0;
    int choice;
    float accountBalance = 5000.00; // Starting balance
    bool isRunning = true;

    printf("=== WELCOME TO THE ATM SYSTEM ===\n");

    // PIN Authentication loop (Maximum 3 attempts)
    while (pinAttempts < 3) {
        printf("Please enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == defaultPin) {
            printf("\nPIN Verified Successfully!\n");
            break;
        } else {
            pinAttempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n\n", 3 - pinAttempts);
        }
    }

    // Terminate if authentication fails
    if (pinAttempts == 3) {
        printf("Too many incorrect attempts. Your card has been blocked.\n");
        return 0;
    }

    // Main ATM transaction loop
    while (isRunning) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(accountBalance);
                break;
            case 2:
                accountBalance = depositMoney(accountBalance);
                break;
            case 3:
                accountBalance = withdrawMoney(accountBalance);
                break;
            case 4:
                printf("\nThank you for using our ATM. Goodbye!\n");
                isRunning = false;
                break;
            default:
                printf("\nInvalid selection. Please choose a valid option.\n");
        }
    }

    return 0;
}

// Function to display the ATM transaction dashboard
void displayMenu() {
    printf("\n--- ATM TRANSACTION MENU ---\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Cash\n");
    printf("3. Withdraw Cash\n");
    printf("4. Exit\n");
    printf("----------------------------\n");
}

// Function to print the current balance
void checkBalance(float balance) {
    printf("\nYour current balance is: $%.2f\n", balance);
}

// Function to handle cash depositions
float depositMoney(float balance) {
    float depositAmount;
    printf("\nEnter the amount to deposit: $");
    scanf("%f", &depositAmount);

    if (depositAmount <= 0) {
        printf("Invalid amount. Transaction canceled.\n");
    } else {
        balance += depositAmount;
        printf("$%.2f deposited successfully.\n", depositAmount);
        printf("New balance: $%.2f\n", balance);
    }
    return balance;
}

// Function to handle cash withdrawals
float withdrawMoney(float balance) {
    float withdrawAmount;
    printf("\nEnter the amount to withdraw: $");
    scanf("%f", &withdrawAmount);

    if (withdrawAmount <= 0) {
        printf("Invalid amount. Transaction canceled.\n");
    } else if (withdrawAmount > balance) {
        printf("Insufficient funds! Your balance is $%.2f\n", balance);
    } else {
        balance -= withdrawAmount;
        printf("$%.2f withdrawn successfully.\n", withdrawAmount);
        printf("Remaining balance: $%.2f\n", balance);
    }
    return balance;
}