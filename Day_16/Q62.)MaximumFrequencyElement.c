#include <stdio.h>

int main() {
    int size;

    // Get the size of the array from the user
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[size];
    int visited[size]; // Array to keep track of counted elements

    // Input array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; // Initialize all elements as not visited
    }

    int maxElement = arr[0];
    int maxCount = 0;

    // Logic to find the maximum frequency element
    for (int i = 0; i < size; i++) {
        // Skip this element if it has already been processed
        if (visited[i] == 1) {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; // Mark duplicate element as visited
            }
        }

        // Update maximum frequency and the corresponding element
        if (count > maxCount) {
            maxCount = count;
            maxElement = arr[i];
        }
    }

    // Output the result
    printf("\nElement with the maximum frequency: %d\n", maxElement);
    printf("It appears %d times.\n", maxCount);

    return 0;
}