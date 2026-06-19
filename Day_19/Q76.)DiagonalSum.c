#include <stdio.h>

int main() {
    int matrix[10][10];
    int size, i, j;
    int main_diagonal_sum = 0;
    int secondary_diagonal_sum = 0;

    // Get the size of the square matrix
    printf("Enter the size of the square matrix (max 10): ");
    scanf("%d", &size);

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Efficiently calculate diagonal sums using a single loop
    for (i = 0; i < size; i++) {
        main_diagonal_sum += matrix[i][i];                  // Elements where row == column
        secondary_diagonal_sum += matrix[i][size - i - 1]; // Elements from top-right to bottom-left
    }

    // Print the results
    printf("\n--- Results ---\n");
    printf("Sum of Main Diagonal elements: %d\n", main_diagonal_sum);
    printf("Sum of Secondary Diagonal elements: %d\n", secondary_diagonal_sum);

    return 0;
}