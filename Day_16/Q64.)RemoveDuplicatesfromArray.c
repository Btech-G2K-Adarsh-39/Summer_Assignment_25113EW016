#include <stdio.h>

int main() {
    int arr[100], size, i, j, k;

    printf("Enter size: ");
    scanf("%d", &size);
    printf("Enter elements: ");
    for (i = 0; i < size; i++) scanf("%d", &arr[i]);

    // Core logic to remove duplicates
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                // Shift elements left
                for (k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--; // Reduce size
                j--;    // Recheck current index
            }
        }
    }

    printf("Result: ");
    for (i = 0; i < size; i++) printf("%d ", arr[i]);
    return 0;
}