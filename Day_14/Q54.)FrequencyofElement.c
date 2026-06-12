#include <stdio.h>

int main() {
    int size, target, count = 0;

    // Get the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the element to search for
    printf("Enter the element to find its frequency: ");
    scanf("%d", &target);

    // Linear search to count occurrences
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }

    // Display the result
    printf("The element %d occurs %d times in the array.\n", target, count);

    return 0;
}