#include <stdio.h>
#include <ctype.h>

// Function to count words in a string
int count_words(const char *str) {
    int count = 0;
    int in_word = 0; // Tracks if we are currently inside a word

    while (*str != '\0') {
        // isspace checks for ' ', '\t', '\n', '\r' etc.
        if (isspace((unsigned char)*str)) {
            in_word = 0; // We hit whitespace, so we are no longer in a word
        } 
        // If it's a non-space character and we weren't already inside a word
        else if (in_word == 0) {
            in_word = 1; // Mark that we entered a word
            count++;     // Increment word count
        }
        str++; // Move to the next character
    }

    return count;
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    
    // fgets safely reads a full line including spaces until newline
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        int words = count_words(sentence);
        printf("Total number of words: %d\n", words);
    }

    return 0;
}