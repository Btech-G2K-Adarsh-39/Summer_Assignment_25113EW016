#include <stdio.h>
#include <ctype.h>

int main() {
    char str[150];
    int vowels = 0;
    int consonants = 0;

    printf("Enter a line of text: ");
    // Safely read a line of text including spaces
    fgets(str, sizeof(str), stdin);

    // Loop through each character until the null terminator is reached
    for (int i = 0; str[i] != '\0'; i++) {
        // Convert character to lowercase to simplify the condition check
        char ch = tolower(str[i]);

        // Check if the character is a vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        }
        // If it's an alphabet letter but not a vowel, it's a consonant
        else if (ch >= 'a' && ch <= 'z') {
            consonants++;
        }
    }

    // Display the results
    printf("Total Vowels: %d\n", vowels);
    printf("Total Consonants: %d\n", consonants);

    return 0;
}