#include <stdio.h>

int main() {
    // Initialize two sample arrays
    int arr1[] = {1, 2, 4, 5, 6, 2, 9};
    int arr2[] = {2, 3, 5, 7, 9, 2, 1};
    
    // Calculate the size of both arrays dynamically
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    // Array to store found common elements to avoid printing duplicates
    int common[100]; 
    int commonCount = 0;

    printf("Array 1: ");
    for(int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    printf("\n");

    printf("Array 2: ");
    for(int i = 0; i < size2; i++) printf("%d ", arr2[i]);
    printf("\n\n");

    printf("Common elements are: ");

    // Step 1: Compare each element of arr1 with arr2
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            
            // Step 2: If a match is found
            if (arr1[i] == arr2[j]) {
                int isDuplicate = 0;
                
                // Step 3: Check if we have already recorded this element
                for (int k = 0; k < commonCount; k++) {
                    if (common[k] == arr1[i]) {
                        isDuplicate = 1;
                        break;
                    }
                }
                
                // Step 4: If it's a new common element, save and print it
                if (!isDuplicate) {
                    common[commonCount] = arr1[i];
                    commonCount++;
                    printf("%d ", arr1[i]);
                }
                
                // Break out of inner loop once matched to save time
                break; 
            }
        }
    }
    
    if (commonCount == 0) {
        printf("None");
    }
    
    printf("\n");
    return 0;
}