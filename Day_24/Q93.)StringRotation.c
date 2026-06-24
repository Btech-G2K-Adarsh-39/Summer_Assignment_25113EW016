#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if str2 is a rotation of str1
bool isRotation(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If lengths are not equal, they cannot be rotations of each other
    if (len1 != len2) {
        return false;
    }

    // Allocate memory for the temporary concatenated string (len1 * 2 + 1 for '\0')
    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return false;
    }

    // Create the concatenated string: temp = str1 + str1
    strcpy(temp, str1);
    strcat(temp, str1);

    // Check if str2 is a substring of temp
    char *match = strstr(temp, str2);

    // Free allocated memory to avoid memory leaks
    free(temp);

    // If match is found, str2 is a rotation
    return (match != NULL);
}

int main() {
    char str1[] = "ABCD";
    char str2[] = "CDAB";

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    if (isRotation(str1, str2)) {
        printf("Result: Yes, one string is a rotation of the other.\n");
    } else {
        printf("Result: No, the strings are not rotations.\n");
    }

    return 0;
}