#include <stdio.h>
#include <string.h>

// Function to reverse a string in-place
void reverseString(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    char temp;

    // Swap characters from both ends until pointers meet
    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }
}

int main() {
    // Array to hold user input string
    char str[100];

    printf("Enter a string: ");
    // Read string including spaces safely using fgets
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character added by fgets
    str[strcspn(str, "\n")] = '\0';

    // Call the reversal function
    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}