#include <stdio.h>

int main() {
    int rows;

    // Ask the user for the number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Outer loop handles the number of rows
    for (int i = 1; i <= rows; i++) {
        
        // Inner loop handles the numbers printed in each row
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        
        // Move to the next line after finishing a row
        printf("\n");
    }

    return 0;
}
