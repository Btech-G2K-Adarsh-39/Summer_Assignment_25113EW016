#include <stdio.h>

int main() {
    int rows, i, j;

    // Ask user for the number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Outer loop handles the rows
    for (i = 1; i <= rows; i++) {
        
        // Inner loop handles printing numbers in each row
        for (j = 1; j <= i; j++) {
            printf("%d ", i); // Prints the current row number 'i' repeatedly
        }
        
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}