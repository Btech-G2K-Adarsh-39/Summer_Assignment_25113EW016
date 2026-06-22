#include <stdio.h>

// Function to remove all spaces from a string
void removeSpaces(char *str) {
    int read = 0;  // Index to scan the original string
    int write = 0; // Index to overwrite the non-space characters

    // Loop until the end of the string is reached
    while (str[read] != '\0') {
        // If current character is not a space, copy it
        if (str[read] != ' ') {
            str[write] = str[read];
            write++;
        }
        read++;
    }
    
    // Add the null terminator at the end of the newly modified string
    str[write] = '\0';
}

int main() {
    // Note: Use a char array, not a string literal pointer (char *str = "..."),
    // because string literals are read-only and will cause a segmentation fault.
    char text[] = " C  Pro gra m m i n g  ";

    printf("Original String: '%s'\n", text);

    // Call the function to remove spaces
    removeSpaces(text);

    printf("Modified String: '%s'\n", text);

    return 0;
}