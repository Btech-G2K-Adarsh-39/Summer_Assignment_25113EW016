#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

// Comparator function for qsort
int compareWordLengths(const void *a, const void *b) {
    // Cast the void pointers to the underlying 2D char array rows
    size_t lengthA = strlen((const char *)a);
    size_t lengthB = strlen((const char *)b);
    
    // Sort in ascending order (shortest to longest)
    // To change to descending order, swap lengthA and lengthB
    return (lengthA > lengthB) - (lengthA < lengthB);
}

int main() {
    int totalWords;
    char words[MAX_WORDS][MAX_LENGTH];

    // Get the total number of words from user
    printf("Enter the number of words: ");
    if (scanf("%d", &totalWords) != 1 || totalWords <= 0) {
        printf("Invalid number of words.\n");
        return 1;
    }

    // Handle array boundary protection
    if (totalWords > MAX_WORDS) {
        printf("Maximum supported words is %d.\n", MAX_WORDS);
        return 1;
    }

    // Input the words
    printf("Enter %d words:\n", totalWords);
    for (int i = 0; i < totalWords; i++) {
        scanf("%s", words[i]);
    }

    // Sort using standard qsort utility
    qsort(words, totalWords, sizeof(words[0]), compareWordLengths);

    // Output the sorted result
    printf("\nWords sorted by length:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s (length: %zu)\n", words[i], strlen(words[i]));
    }

    return 0;
}