#include <stdio.h>

int main() {
    int rows, cols;
    int isSymmetric = 1; // Flag: 1 means true, 0 means false

    // Step 1: Input dimensions
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Step 2: Validate if it is a square matrix
    if (rows != cols) {
        printf("The matrix is not square, so it cannot be symmetric.\n");
        return 0;
    }

    int matrix[rows][cols];

    // Step 3: Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Step 4: Check for symmetry
    // We only need to check elements above the main diagonal (j > i)
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; // Breakdown found
                break;
            }
        }
        if (!isSymmetric) {
            break;
        }
    }

    // Step 5: Output the result
    if (isSymmetric) {
        printf("\nThe matrix is a Symmetric Matrix.\n");
    } else {
        printf("\nThe matrix is NOT a Symmetric Matrix.\n");
    }

    return 0;
}