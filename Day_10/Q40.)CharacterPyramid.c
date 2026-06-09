#include <stdio.h>

int main() {
    int rows = 5;
    int i, j;

    for (i = 1; i <= rows; i++) {
        
        // 1. Inner loop for leading spaces
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }

        // 2. Inner loop for ascending characters
        for (j = 1; j <= i; j++) {
            printf("%c", 'A' + j - 1);
        }

        
        for (j = i - 1; j >= 1; j--) {
            printf("%c", 'A' + j - 1);
        }

       
        printf("\n");
    }

    return 0;
}