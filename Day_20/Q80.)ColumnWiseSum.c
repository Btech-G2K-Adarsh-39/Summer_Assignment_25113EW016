#include <stdio.h>

int main() {
    int rows, cols;
    int i, j, colSum;

    // Ask user for the dimensions of the matrix
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    // Input matrix elements from the user
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the original matrix
    printf("\nThe given matrix is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n--- Column-wise Sum ---\n");
    // Outer loop iterates through each column
    for (j = 0; j < cols; j++) {
        colSum = 0; // Reset sum for the next column
        
        // Inner loop iterates through each row of the current column
        for (i = 0; i < rows; i++) {
            colSum += matrix[i][j];
        }
        
        printf("Sum of Column %d = %d\n", j + 1, colSum);
    }

    return 0;
}