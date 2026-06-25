#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_LENGTH 50

int main() {
    char names[MAX_NAMES][MAX_LENGTH];
    char temp[MAX_LENGTH];
    int n, i, j;

    // 1. Get the number of names from the user
    printf("Enter the number of names: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_NAMES) {
        printf("Invalid number of names.\n");
        return 1;
    }

    // Consume the trailing newline character left over by scanf
    getchar(); 

    // 2. Input the names
    printf("Enter %d names (one per line):\n", n);
    for (i = 0; i < n; i++) {
        // Read string including spaces; strip the trailing newline if present
        if (fgets(names[i], MAX_LENGTH, stdin) != NULL) {
            names[i][strcspn(names[i], "\n")] = '\0';
        }
    }

    // 3. Sort the names using Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // If the current name is alphabetically greater than the next name, swap them
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    // 4. Display the sorted names
    printf("\nNames in alphabetical order:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}