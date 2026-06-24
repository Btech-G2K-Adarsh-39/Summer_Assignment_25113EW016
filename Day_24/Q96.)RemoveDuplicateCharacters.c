#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to remove duplicate characters in-place
void removeDuplicates(char *str) {
    // Array to track seen ASCII characters (initialized to false)
    bool seen[256] = { false };
    
    int readIndex = 0;
    int writeIndex = 0;
    
    // Traverse the string
    while (str[readIndex] != '\0') {
        unsigned char ch = str[readIndex];
        
        // If the character hasn't been seen yet
        if (!seen[ch]) {
            seen[ch] = true;             // Mark it as seen
            str[writeIndex] = str[readIndex]; // Copy to write position
            writeIndex++;                // Advance write position
        }
        readIndex++; // Move to the next character
    }
    
    // Null-terminate the modified string
    str[writeIndex] = '\0';
}

int main() {
    // Use a character array since string literals like "hello" are read-only
    char text[100];
    
    printf("Enter a string: ");
    // Read string including spaces safely, stopping at the newline character
    if (fgets(text, sizeof(text), stdin)) {
        // Remove the trailing newline character added by fgets, if present
        size_t len = strlen(text);
        if (len > 0 && text[len - 1] == '\n') {
            text[len - 1] = '\0';
        }
        
        printf("Original string: %s\n", text);
        
        removeDuplicates(text);
        
        printf("String after removing duplicates: %s\n", text);
    }
    
    return 0;
}