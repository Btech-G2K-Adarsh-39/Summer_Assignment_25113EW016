#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum string size
#define ASCII_SIZE 256 // Total unique ASCII characters

int main() {
    char str[MAX_SIZE];
    int freq[ASCII_SIZE] = {0}; // Initialize all frequencies to 0
    int i, max_freq;
    char max_char;

    printf("Enter any string: ");
    // Read string including spaces safely up to MAX_SIZE - 1
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if appended by fgets
    str[strcspn(str, "\n")] = '\0';

    // Count frequency of each character in the string
    for (i = 0; str[i] != '\0'; i++) {
        // Cast to unsigned char to safely handle negative values or extended ASCII
        unsigned char index = (unsigned char)str[i];
        freq[index]++;
    }

    // Find the character with the maximum frequency
    max_freq = 0;
    max_char = str[0]; // Fallback if string is empty

    for (i = 0; i < ASCII_SIZE; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            max_char = (char)i;
        }
    }

    // Output the result
    if (max_freq > 0) {
        printf("Maximum occurring character is '%c' and it appears %d times.\n", max_char, max_freq);
    } else {
        printf("The string is empty.\n");
    }

    return 0;
}