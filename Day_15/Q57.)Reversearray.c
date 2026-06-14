#include <stdio.h>

// Function to reverse the array in-place
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    int temp;

    // Swap elements from both ends moving inward
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move the markers toward the center
        start++;
        end--;
    }
}

// Function to print the array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, size);

    // Call function to reverse the array
    reverseArray(arr, size);

    printf("Reversed Array: ");
    printArray(arr, size);

    return 0;
}