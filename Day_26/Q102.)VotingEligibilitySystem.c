#include <stdio.h>

int main() {
    int age;

    // Prompt the user to enter their age
    printf("===================================\n");
    printf("    VOTING ELIGIBILITY TEST        \n");
    printf("===================================\n");
    printf("Enter your age: ");
    
    // Read the user input
    if (scanf("%d", &age) != 1) {
        printf("Error: Invalid input. Please enter a valid number.\n");
        return 1; // Exit with error code
    }

    // Validate the age and check eligibility
    if (age < 0) {
        printf("Error: Age cannot be a negative number.\n");
    } else if (age >= 18) {
        printf("Result: Congratulations! You are eligible to vote.\n");
    } else {
        int years_left = 18 - age;
        printf("Result: Sorry, you are not eligible to vote yet.\n");
        printf("You need to wait %d more year(s) to become eligible.\n", years_left);
    }

    printf("===================================\n");
    return 0;
}