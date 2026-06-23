#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256

// Function to find the first non-repeating character
char findFirstUnique(const char *str) {
    int count[MAX_CHARS] = {0};
    int i;

    // Step 1: Count frequencies of each character
    for (i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }

    // Step 2: Scan string from left to right to find the first unique character
    for (i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] == 1) {
            return str[i]; // Return the first character with a frequency of 1
        }
    }

    return '\0'; // Return null terminator if no unique character exists
}

int main() {
    char str[] = "cprogrammingcode";
    char result = findFirstUnique(str);

    if (result != '\0') {
        printf("The first non-repeating character is: '%c'\n", result);
    } else {
        printf("All characters repeat or the string is empty.\n");
    }

    return 0;
}