#include <stdio.h>

// Function to reverse a section of the array between start and end indices
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to left rotate the array by d positions
void leftRotate(int arr[], int d, int n) {
    if (n == 0) return;
    
    // Handle cases where d is greater than the size of the array
    d = d % n; 
    
    // Step 1: Reverse the first d elements
    reverse(arr, 0, d - 1);
    
    // Step 2: Reverse the remaining elements
    reverse(arr, d, n - 1);
    
    // Step 3: Reverse the whole array
    reverse(arr, 0, n - 1);
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2; // Number of positions to rotate left

    printf("Original Array: ");
    printArray(arr, n);

    leftRotate(arr, d, n);

    printf("Array after left rotation by %d positions: ", d);
    printArray(arr, n);

    return 0;
}