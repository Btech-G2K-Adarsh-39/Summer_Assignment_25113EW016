#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;
    int i, j, k;

    // 1. Input dimensions of the first matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);

    // 2. Input dimensions of the second matrix
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    // 3. Check compatibility for matrix multiplication
    if (c1 != r2) {
        printf("\nError: Multiplication not possible!\n");
        printf("Columns of the first matrix must match rows of the second matrix.\n");
        return 1;
    }

    // 4. Input elements of the first matrix
    printf("\nEnter elements of the first matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("Element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // 5. Input elements of the second matrix
    printf("\nEnter elements of the second matrix:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("Element b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    // 6. Initialize the result matrix to 0 and multiply matrices
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // 7. Display the final result matrix
    printf("\nResultant Matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}