#include <stdio.h>
#include <limits.h> // Required for INT_MIN

int main() {
    int arr[100], size, i;
    int largest, second_largest;

    // Ask user for the size of the array
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1 || size < 2) {
        printf("Error: Array must contain at least 2 elements.\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize both variables to the lowest possible integer value
    largest = INT_MIN;
    second_largest = INT_MIN;

    // Single pass traversal to find largest and second largest
    for (i = 0; i < size; i++) {
        if (arr[i] > largest) {
            // The old largest becomes the second largest
            second_largest = largest;
            // The current element becomes the new largest
            largest = arr[i];
        } 
        // If the current element is smaller than 'largest' but larger than 'second_largest'
        else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    // Print results and handle edge cases
    printf("\nLargest element: %d\n", largest);
    if (second_largest == INT_MIN) {
        printf("Second largest element does not exist (all elements are equal).\n");
    } else {
        printf("Second largest element: %d\n", second_largest);
    }

    return 0;
}