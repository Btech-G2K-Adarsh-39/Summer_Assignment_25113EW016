#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256

// Function to check if two strings are anagrams
int check_anagram(const char *str1, const char *str2) {
    int count[MAX_CHARS] = {0};
    int i;

    // If lengths are different, they cannot be anagrams
    if (strlen(str1) != strlen(str2)) {
        return 0; 
    }

    // Increment count for first string and decrement for second string
    for (i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }

    // If all frequencies are zero, the strings are anagrams
    for (i = 0; i < MAX_CHARS; i++) {
        if (count[i] != 0) {
            return 0; 
        }
    }

    return 1; 
}

int main() {
    char s1[100], s2[100];

    printf("Enter the first string: ");
    // Read string including spaces (stops at newline)
    scanf("%99[^\n]", s1);
    
    // Clear the input buffer newline character
    getchar(); 

    printf("Enter the second string: ");
    scanf("%99[^\n]", s2);

    if (check_anagram(s1, s2)) {
        printf("\n\"%s\" and \"%s\" are anagrams.\n", s1, s2);
    } else {
        printf("\n\"%s\" and \"%s\" are NOT anagrams.\n", s1, s2);
    }

    return 0;
}