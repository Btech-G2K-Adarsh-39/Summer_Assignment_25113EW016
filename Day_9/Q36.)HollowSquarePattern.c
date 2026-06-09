#include <stdio.h>

int main() {
    int i, j, side;

    // Input the side length of the square from the user
    printf("Enter the side of the square: ");
    scanf("%d", &side);

    // Loop through each row
    for(i = 1; i <= side; i++) {
        // Loop through each column
        for(j = 1; j <= side; j++) {
            // Print star only at the boundaries (first/last row, first/last column)
            if(i == 1 || i == side || j == 1 || j == side) {
                printf("* ");
            } else {
                // Print space for the hollow center
                printf("  ");
            }
        }
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}