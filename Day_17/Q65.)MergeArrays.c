#include <stdio.h>

int main() {
    int arr1[50], arr2[50], merged[100];
    int size1, size2, i;

    // Input sizes and elements
    printf("Enter sizes and elements for two arrays...\n");
    scanf("%d %d", &size1, &size2);
    // ... (input loops omitted for brevity)

    // Merge: Copy arr1, then append arr2
    for (i = 0; i < size1; i++) merged[i] = arr1[i];
    for (i = 0; i < size2; i++) merged[size1 + i] = arr2[i];

    // Print result
    for (i = 0; i < size1 + size2; i++) printf("%d ", merged[i]);
    return 0;
}