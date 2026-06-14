#include <stdio.h>

// Function to move all zeroes to the end of the array
void moveZeroesToEnd(int arr[], int size) {
    int count = 0; // Tracks the position for the next non-zero element

    // Step 1: Travel through the array. 
    // If the element is non-zero, shift it forward to the 'count' index.
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[count] = arr[i];
            count++;
        }
    }

    // Step 2: Fill the remaining space from 'count' to the end with zeroes.
    while (count < size) {
        arr[count] = 0;
        count++;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 0, 2, 0, 4, 3, 0, 5, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, size);

    // Call the function to modify the array in-place
    moveZeroesToEnd(arr, size);

    printf("Modified Array: ");
    printArray(arr, size);

    return 0;
}