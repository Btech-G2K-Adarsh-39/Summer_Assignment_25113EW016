#include <stdio.h>

int main() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c], b[r][c], res[r][c];

    printf("Enter Matrix A: \n");
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++) scanf("%d", &a[i][j]);

    printf("Enter Matrix B: \n");
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++) scanf("%d", &b[i][j]);

    // Subtraction logic
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("Result:\n");
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}