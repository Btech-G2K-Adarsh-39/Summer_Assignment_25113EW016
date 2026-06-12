#include <stdio.h>

int main() {
    int n;

    // Ask user for the size of the array
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];
    // This array will keep track of whether an element was already counted/printed
    int visited[n]; 

    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; // Initialize visited tracking array to 0
    }

    printf("\nDuplicate elements in the array are: ");
    int found_duplicate = 0;

    // Logic to find duplicates
    for (int i = 0; i < n; i++) {
        // If this element has already been processed as a duplicate, skip it
        if (visited[i] == 1) {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; // Mark the found duplicate element as visited
            }
        }

        // If the element appeared more than once, print it
        if (count > 1) {
            printf("%d ", arr[i]);
            found_duplicate = 1;
        }
    }

    if (!found_duplicate) {
        printf("None");
    }
    
    printf("\n");
    return 0;
}