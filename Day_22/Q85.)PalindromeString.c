#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    // Remove the newline character if read by fgets
    if (str[right] == '\n') {
        str[right] = '\0';
        right--;
    }

    // Compare characters from both ends moving towards the center
    while (left < right) {
        if (str[left] != str[right]) {
            return false; // Mismatch found, not a palindrome
        }
        left++;
        right--;
    }
    return true; // All characters matched
}

int main() {
    char str[100];

    printf("Enter a string: ");
    // Using fgets instead of gets for safety against buffer overflow
    if (fgets(str, sizeof(str), stdin) != NULL) {
        
        if (isPalindrome(str)) {
            printf("The string is a palindrome.\n");
        } else {
            printf("The string is not a palindrome.\n");
        }
    }

    return 0;
}