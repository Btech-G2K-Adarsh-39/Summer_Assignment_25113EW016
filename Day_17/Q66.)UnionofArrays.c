#include <stdio.h>

// Function to check if an element is already present in the result array
int isPresent(int element, int res[], int size) {
    for (int i = 0; i < size; i++) {
        if (res[i] == element) {
            return 1; // Element is already in the array
        }
    }
    return 0; // Element is not found
}

// Function to find the union of two arrays
int findUnion(int arr1[], int size1, int arr2[], int size2, int unionResult[]) {
    int k = 0; // Tracks the size of the union result array

    // Copy unique elements from the first array
    for (int i = 0; i < size1; i++) {
        if (!isPresent(arr1[i], unionResult, k)) {
            unionResult[k++] = arr1[i];
        }
    }

    // Copy unique elements from the second array
    for (int i = 0; i < size2; i++) {
        if (!isPresent(arr2[i], unionResult, k)) {
            unionResult[k++] = arr2[i];
        }
    }

    return k; // Return the final size of the union array
}

int main() {
    // Input arrays with duplicate values
    int arr1[] = {1, 2, 3, 2, 1, 4};
    int arr2[] = {3, 4, 5, 6, 4};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Maximum possible size of union is the sum of both array sizes
    int unionResult[size1 + size2];

    // Find the union and get its final size
    int unionSize = findUnion(arr1, size1, arr2, size2, unionResult);

    // Print the final result
    printf("Union of the two arrays: ");
    for (int i = 0; i < unionSize; i++) {
        printf("%d ", unionResult[i]);
    }
    printf("\n");

    return 0;
}