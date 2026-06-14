#include <stdio.h>

// Function to find and print pairs with the given sum
void findPair(int arr[], int size, int targetSum) {
    int found = 0;

    // Outer loop selects the first element
    for (int i = 0; i < size - 1; i++) {
        // Inner loop selects the second element
        for (int j = i + 1; j < size; j++) {
            // Check if the sum of the two elements matches the target
            if (arr[i] + arr[j] == targetSum) {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No pair found with the sum %d.\n", targetSum);
    }
}

int main() {
    // Initialize sample array and the target sum
    int arr[] = {8, 7, 2, 5, 3, 1};
    int targetSum = 10;
    
    // Calculate the total number of elements in the array
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTarget Sum: %d\n\n", targetSum);

    // Call the function to find the pairs
    findPair(arr, size, targetSum);

    return 0;
}