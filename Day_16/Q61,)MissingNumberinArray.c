#include <stdio.h>

// Function to find the missing number using Bitwise XOR
int findMissingNumber(int arr[], int size) {
    int xor_all = 0;
    int xor_arr = 0;
    int N = size + 1; // Expected range of elements is from 1 to N

    // XOR all numbers from 1 to N
    for (int i = 1; i <= N; i++) {
        xor_all ^= i;
    }

    // XOR all elements present in the array
    for (int i = 0; i < size; i++) {
        xor_arr ^= arr[i];
    }

    // The missing number is the XOR difference between the two sets
    return xor_all ^ xor_arr;
}

int main() {
    // Array of size 7 containing distinct numbers from 1 to 8 (6 is missing)
    int arr[] = {1, 2, 4, 6, 3, 7, 8}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    // Call the function and fetch the missing number
    int missingNum = findMissingNumber(arr, size);

    // Print the final result
    printf("The missing number in the array is: %d\n", missingNum);

    return 0;
}