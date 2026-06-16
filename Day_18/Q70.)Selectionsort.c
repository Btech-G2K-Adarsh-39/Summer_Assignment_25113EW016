#include <stdio.h>

// Function to swap two elements using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Selection Sort
void selectionSort(int arr[], int size) {
    // Loop to move the boundary of the unsorted subarray
    for (int i = 0; i < size - 1; i++) {
        // Assume the first unsorted element is the minimum
        int min_idx = i;
        
        // Loop to find the actual minimum element in the remaining unsorted array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update index of the minimum element
            }
        }
        
        // Swap the found minimum element with the first unsorted element
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
        }
    }
}

// Function to print the array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code to test the program
int main() {
    int data[] = {64, 25, 12, 22, 11};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("Original array:\n");
    printArray(data, size);
    
    // Call selection sort function
    selectionSort(data, size);
    
    printf("Sorted array in ascending order:\n");
    printArray(data, size);
    
    return 0;
}