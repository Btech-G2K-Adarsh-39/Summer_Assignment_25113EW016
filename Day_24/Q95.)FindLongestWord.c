#include <stdio.h>
#include <string.h>

int main() {
    char sentence[500];
    char longest_word[100] = "";
    int max_length = 0;

    // Prompt user for input
    printf("Enter a sentence: ");
    
    // Read an entire line safely (handles spaces)
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline character added by fgets
    sentence[strcspn(sentence, "\n")] = '\0';

    // Tokenize sentence using spaces and standard punctuation as delimiters
    char *word = strtok(sentence, " ,.-!?\t");

    // Loop through all words in the sentence
    while (word != NULL) {
        int current_length = strlen(word);

        // If current word is longer than the previous maximum
        if (current_length > max_length) {
            max_length = current_length;
            strcpy(longest_word, word); // Save the longest word
        }

        // Get the next word
        word = strtok(NULL, " ,.-!?\t");
    }

    // Output results
    if (max_length > 0) {
        printf("\nLongest word: \"%s\"\n", longest_word);
        printf("Length: %d characters\n", max_length);
    } else {
        printf("\nNo words found.\n");
    }

    return 0;
}