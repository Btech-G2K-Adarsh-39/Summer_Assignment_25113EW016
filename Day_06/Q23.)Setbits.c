#include <stdio.h>

// Function to count set bits using Brian Kernighan's Algorithm
int countSetBits(unsigned int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1); // Clears the rightmost set bit
        count++;
    }
    return count;
}

int main() {
    unsigned int num;
    printf("Enter an integer: ");
    scanf("%u", &num);

    printf("Number of set bits: %d\n", countSetBits(num));
    return 0;
}
