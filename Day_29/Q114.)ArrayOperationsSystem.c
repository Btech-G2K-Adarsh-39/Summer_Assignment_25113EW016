#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function prototypes
void createArray(int arr[], int *size);
void displayArray(int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
int searchElement(int arr[], int size, int element);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, index;

    while (1) {
        printf("\n==============================");
        printf("\n    ARRAY OPERATIONS SYSTEM   ");
        printf("\n==============================");
        printf("\n1. Create / Initialize Array");
        printf("\n2. Display Array Elements");
        printf("\n3. Insert an Element");
        printf("\n4. Delete an Element");
        printf("\n5. Search for an Element");
        printf("\n6. Exit");
        printf("\n==============================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                if (size == 0) {
                    printf("\nArray is empty! Nothing to search.\n");
                } else {
                    printf("\nEnter element to search: ");
                    scanf("%d", &element);
                    index = searchElement(arr, size, element);
                    if (index != -1) {
                        printf("Element found at Position %d (Index %d).\n", index + 1, index);
                    } else {
                        printf("Element not found in the array.\n");
                    }
                }
                break;
            case 6:
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// 1. Create Array
void createArray(int arr[], int *size) {
    printf("\nEnter the number of elements (Max %d): ", MAX_SIZE);
    scanf("%d", size);

    if (*size < 0 || *size > MAX_SIZE) {
        printf("Invalid size! Resetting size to 0.\n");
        *size = 0;
        return;
    }

    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully.\n");
}

// 2. Display Array
void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("\nArray is empty!\n");
        return;
    }
    printf("\nArray Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 3. Insert Element
void insertElement(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("\nArray Overflow! Cannot insert more elements.\n");
        return;
    }

    int pos, element;
    printf("\nEnter the position to insert (1 to %d): ", *size + 1);
    scanf("%d", &pos);

    // Validate position boundaries
    if (pos < 1 || pos > *size + 1) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter the element value: ");
    scanf("%d", &element);

    // Shift elements to the right to make space
    for (int i = *size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element at the exact index
    arr[pos - 1] = element;
    (*size)++; // Increment array size tracker
    printf("Element inserted successfully.\n");
}

// 4. Delete Element
void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("\nArray Underflow! Nothing to delete.\n");
        return;
    }

    int pos;
    printf("\nEnter the position to delete (1 to %d): ", *size);
    scanf("%d", &pos);

    // Validate position boundaries
    if (pos < 1 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the left to overwrite the deleted entry
    for (int i = pos - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--; // Decrement array size tracker
    printf("Element deleted successfully.\n");
}

// 5. Linear Search
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Return element array index 
        }
    }
    return -1; // Return if missing
}