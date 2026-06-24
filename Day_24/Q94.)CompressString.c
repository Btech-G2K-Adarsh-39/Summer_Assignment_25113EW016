#include <stdio.h>
#include <string.h>

// Function to compress the input string
void compressString(const char *src, char *dest) {
    int i = 0;
    int j = 0; // Index for the destination string
    int len = strlen(src);

    while (i < len) {
        // Record the current character
        dest[j++] = src[i];
        
        int count = 1;
        // Count consecutive occurrences of the character
        while (i + 1 < len && src[i] == src[i + 1]) {
            count++;
            i++;
        }

        // Convert the count to a string and append it to dest
        // sprintf returns the number of characters written
        j += sprintf(&dest[j], "%d", count);
        
        // Move to the next unique character
        i++;
    }
    
    // Null-terminate the compressed string
    dest[j] = '\0';
}

int main() {
    char source[1000];
    // Allocate twice the size to safely handle the worst-case scenario (e.g., "abcd" -> "a1b1c1d1")
    char compressed[2000]; 

    printf("Enter a string to compress: ");
    // Read input, including spaces, up to 999 characters
    if (fgets(source, sizeof(source), stdin) != NULL) {
        // Remove trailing newline character if present
        source[strcspn(source, "\n")] = '\0';

        // Check if string is empty
        if (strlen(source) == 0) {
            printf("Compressed string: (empty)\n");
            return 0;
        }

        // Perform compression
        compressString(source, compressed);

        // Display results
        printf("\nOriginal String  : %s", source);
        printf("\nCompressed String: %s\n", compressed);
    }

    return 0;
}