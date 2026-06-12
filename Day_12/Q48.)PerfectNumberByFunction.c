#include <stdio.h>


int isPerfect(int num) {
    // Perfect numbers must be positive integers greater than 1
    if (num <= 1) {
        return 0; 
    }

    int sum = 0;

    // Loop up to num/2 because no proper divisor can be larger than half the number
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i; // Add divisor to the sum
        }
    }

    // Return 1 (true) if sum of divisors equals original number, else 0 (false)
    if (sum == num) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int number;

    // Get input from the user
    printf("Enter a positive integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Call the function and print the corresponding result
    if (isPerfect(number)) {
        printf("%d is a Perfect Number.\n", number);
    } else {
        printf("%d is NOT a Perfect Number.\n", number);
    }

    return 0;
}