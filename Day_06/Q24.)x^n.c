#include <stdio.h>

// Function to calculate x^n without pow()
double calculate_power(double x, int n) {
    double result = 1.0;
    
    // Handle the mathematically undefined case of 0^0 or 0^negative
    if (x == 0 && n <= 0) {
        printf("Error: Undefined mathematical operation.\n");
        return 0.0;
    }

    // Convert negative exponent to positive for the loop
    int abs_n = (n < 0) ? -n : n;

    // Multiply x exactly abs_n times
    for (int i = 0; i < abs_n; i++) {
        result *= x;
    }

    // If original exponent was negative, return the reciprocal
    if (n < 0) {
        return 1.0 / result;
    }

    return result;
}

int main() {
    double base;
    int exponent;

    printf("Enter base (x): ");
    if (scanf("%lf", &base) != 1) {
        printf("Invalid input for base.\n");
        return 1;
    }

    printf("Enter integer exponent (n): ");
    if (scanf("%d", &exponent) != 1) {
        printf("Invalid input for exponent.\n");
        return 1;
    }

    double answer = calculate_power(base, exponent);
    
    printf("%.2lf^%d = %.6lf\n", base, exponent, answer);

    return 0;
}