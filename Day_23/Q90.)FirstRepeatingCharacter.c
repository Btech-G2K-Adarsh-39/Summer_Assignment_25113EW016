#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256 // Maximum number of characters in extended ASCII

// Function to find the first repeating character
char findFirstRepeating(char str[]) {
    // Array to keep track of visited characters initialized to 0
    int visited[MAX_CHAR] = {0};

    // Traverse the string from left to right
    for (int i = 0; str[i] != '\0'; i++) {
        // Cast character to unsigned char to avoid negative indexing
        unsigned char ch = str[i];

        // If the character is already visited, it is the first repeating character
        if (visited[ch] == 1) {
            return str[i];
        }

        // Mark the character as visited
        visited[ch] = 1;
    }

    // Return null character if no repeating character is found
    return '\0';
}

int main() {
    char str[100];

    printf("Enter a string: ");
    // Read string including spaces (excluding newline)
    scanf("%99[^\n]", str);

    char result = findFirstRepeating(str);

    if (result != '\0') {
        printf("The first repeating character is: '%c'\n", result);
    } else {
        printf("No repeating characters found.\n");
    }

    return 0;
}