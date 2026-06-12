#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    // Loop through each element of the array
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if target matches current element
        }
    }
    return -1; // Return -1 if target is not found
}

int main() {
    int size, target, result;

    // Get the size of the array from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    // Get array elements from the user
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the target value to search for
    printf("Enter the value to search for: ");
    scanf("%d", &target);

    // Call the linear search function
    result = linearSearch(arr, size, target);

    // Display the final outcome
    if (result != -1) {
        printf("Element found at index: %d (Position: %d)\n", result, result + 1);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}