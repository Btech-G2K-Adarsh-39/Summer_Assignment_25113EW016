#include <stdio.h>

// Recursive function to find the nth Fibonacci number
int fibonacci(int n) {
    // Base Case: F(0) = 0 and F(1) = 1
    if (n <= 1) {
        return n;
    }
    // Recursive Case: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int terms;

    // Prompt the user for the number of terms
    printf("Enter the number of terms for the Fibonacci series: ");
    if (scanf("%d", &terms) != 1 || terms < 0) {
        printf("Please enter a valid non-negative integer.\n");
        return 1;
    }

    printf("Fibonacci Sequence: ");
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
