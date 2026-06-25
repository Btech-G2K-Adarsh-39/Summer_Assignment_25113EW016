#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256  // Supports standard ASCII characters

void findCommonCharacters(const char *str1, const char *str2) {
    int freq1[MAX_CHAR] = {0};
    int freq2[MAX_CHAR] = {0};
    int found = 0;

    // Count character frequencies in the first string
    for (int i = 0; str1[i] != '\0'; i++) {
        freq1[(unsigned char)str1[i]]++;
    }

    // Count character frequencies in the second string
    for (int i = 0; str2[i] != '\0'; i++) {
        freq2[(unsigned char)str2[i]]++;
    }

    printf("Common characters: ");

    // Compare and print common characters
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq1[i] > 0 && freq2[i] > 0) {
            // Print the character (handles spaces and symbols)
            printf("'%c' ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    // Example test strings
    char string1[] = "hello world";
    char string2[] = "woodland";

    printf("String 1: %s\n", string1);
    printf("String 2: %s\n", string2);

    findCommonCharacters(string1, string2);

    return 0;
}