#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to clear the input buffer to prevent skipping inputs
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to safely read a string containing spaces
void read_string(char *str, int size) {
    fgets(str, size, stdin);
    // Remove the trailing newline character added by fgets
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    char str1[200], str2[100];
    int choice;

    while (1) {
        printf("\n====================================");
        printf("\n      STRING OPERATIONS MENU        ");
        printf("\n====================================");
        printf("\n1. Find Length of a String");
        printf("\n2. Copy a String");
        printf("\n3. Concatenate (Join) Two Strings");
        printf("\n4. Compare Two Strings");
        printf("\n5. Reverse a String");
        printf("\n6. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            clear_buffer();
            continue;
        }
        
        clear_buffer(); // Clear buffer after numeric input

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                read_string(str1, sizeof(str1));
                printf("Length of the string: %lu\n", strlen(str1));
                break;

            case 2:
                printf("\nEnter the source string to copy: ");
                read_string(str1, sizeof(str1));
                strcpy(str2, str1);
                printf("Successfully copied! Destination string: \"%s\"\n", str2);
                break;

            case 3:
                printf("\nEnter first string: ");
                read_string(str1, sizeof(str1));
                printf("Enter second string to append: ");
                read_string(str2, sizeof(str2));
                
                // Ensure there is enough space in str1 before concatenating
                if (strlen(str1) + strlen(str2) < sizeof(str1)) {
                    strcat(str1, str2);
                    printf("Concatenated string: \"%s\"\n", str1);
                } else {
                    printf("Error: Resulting string is too long for the buffer.\n");
                }
                break;

            case 4:
                printf("\nEnter first string: ");
                read_string(str1, sizeof(str1));
                printf("Enter second string: ");
                read_string(str2, sizeof(str2));
                
                int result = strcmp(str1, str2);
                if (result == 0) {
                    printf("Both strings are identical.\n");
                } else if (result > 0) {
                    printf("First string is lexicographically greater than the second.\n");
                } else {
                    printf("Second string is lexicographically greater than the first.\n");
                }
                break;

            case 5:
                printf("\nEnter a string to reverse: ");
                read_string(str1, sizeof(str1));
                
                int len = strlen(str1);
                printf("Reversed string: ");
                for (int i = len - 1; i >= 0; i--) {
                    putchar(str1[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please select an option between 1 and 6.\n");
        }
    }

    return 0;
}