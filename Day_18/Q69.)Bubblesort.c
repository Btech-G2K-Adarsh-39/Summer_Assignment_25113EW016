#include <stdio.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    // Outer loop for number of passes
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Reset flag for the current pass

        // Inner loop for adjacent element comparisons
        for (j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = 1; // Mark that a swap occurred
            }
        }

        // Optimization: If no elements were swapped, the array is already sorted
        if (swapped == 0) {
            break;
        }
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // Dynamically calculate array size

    printf("Unsorted array: \n");
    printArray(arr, n);

    // Call the sorting function
    bubbleSort(arr, n);

    printf("Sorted array in ascending order: \n");
    printArray(arr, n);

    return 0;
}