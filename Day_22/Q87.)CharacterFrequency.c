#include <stdio.h>

int main() {
    char str[1000];
    int freq[256] = {0}; // Array to store frequency of all 256 ASCII characters
    int i;

    printf("Enter a string: ");
    // Using fgets instead of gets for safe string input handling
    fgets(str, sizeof(str), stdin);

    // Count the frequency of each character
    for (i = 0; str[i] != '\0'; i++) {
        // Skip the newline character captured by fgets if present
        if (str[i] == '\n') {
            continue;
        }
        freq[(unsigned char)str[i]]++;
    }

    // Display the frequency of characters present in the string
    printf("\nCharacter Frequencies:\n");
    for (i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("'%c' : %d\n", i, freq[i]);
        }
    }

    return 0;
}