#include <stdio.h>

// Function declaration to check palindrome
int isPalindrome(int number) {
    int remainder;
    int reversed = 0;
    int original = number;

    // Negative numbers are not palindromes
    if (number < 0) {
        return 0; 
    }

    // Logic to reverse the integer
    while (number != 0) {
        remainder = number % 10;
        reversed = (reversed * 10) + remainder;
        number /= 10;
    }

    // Returns 1 (true) if palindrome, 0 (false) otherwise
    return (original == reversed);
}

int main() {
    int inputNumber;

    // Get input from the user
    printf("Enter an integer: ");
    scanf("%d", &inputNumber);

    // Call the function and display the result
    if (isPalindrome(inputNumber)) {
        printf("%d is a palindrome.\n", inputNumber);
    } else {
        printf("%d is not a palindrome.\n", inputNumber);
    }

    return 0;
}