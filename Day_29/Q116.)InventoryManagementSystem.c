#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

// Structure to define an inventory item
typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

// Global array to hold items and a counter for current size
Item inventory[MAX_ITEMS];
int itemCount = 0;

// Function declarations
void menu();
void addItem();
void viewInventory();
void updateItem();
void deleteItem();
void searchItem();
int findItemIndexById(int id);
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        menu();
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewInventory(); break;
            case 3: updateItem(); break;
            case 4: deleteItem(); break;
            case 5: searchItem(); break;
            case 6: 
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// Displays the primary user interface menu
void menu() {
    printf("\n=================================");
    printf("\n    INVENTORY MANAGEMENT SYSTEM  ");
    printf("\n=================================");
    printf("\n1. Add New Item");
    printf("\n2. View All Items");
    printf("\n3. Update Item Stock/Price");
    printf("\n4. Delete An Item");
    printf("\n5. Search For An Item");
    printf("\n6. Exit Program");
    printf("\n=================================\n");
}

// Adds a new item to the inventory array
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("\nError: Inventory capacity reached!\n");
        return;
    }

    int id;
    printf("\nEnter Unique Item ID (Integer): ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID format!\n");
        clearInputBuffer();
        return;
    }

    // Ensure the Item ID does not already exist
    if (findItemIndexById(id) != -1) {
        printf("Error: An item with ID %d already exists.\n", id);
        return;
    }

    inventory[itemCount].id = id;
    clearInputBuffer(); // Clear the buffer before reading a string

    printf("Enter Item Name: ");
    fgets(inventory[itemCount].name, NAME_LENGTH, stdin);
    inventory[itemCount].name[strcspn(inventory[itemCount].name, "\n")] = 0; // Remove trailing newline

    printf("Enter Item Quantity: ");
    if (scanf("%d", &inventory[itemCount].quantity) != 1 || inventory[itemCount].quantity < 0) {
        printf("Invalid quantity! Must be 0 or greater.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter Item Price ($): ");
    if (scanf("%f", &inventory[itemCount].price) != 1 || inventory[itemCount].price < 0.0) {
        printf("Invalid price! Must be a positive value.\n");
        clearInputBuffer();
        return;
    }

    itemCount++;
    printf("\nSuccess: Item added successfully!\n");
}

// Displays all stored inventory items in a formatted table
void viewInventory() {
    if (itemCount == 0) {
        printf("\nThe inventory is currently empty.\n");
        return;
    }

    printf("\n%-10s %-25s %-12s %-10s\n", "Item ID", "Item Name", "Quantity", "Price");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%-10d %-25s %-12d $%-9.2f\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Updates an existing item's quantity or price
void updateItem() {
    int id;
    printf("\nEnter the Item ID you wish to update: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID format!\n");
        clearInputBuffer();
        return;
    }

    int index = findItemIndexById(id);
    if (index == -1) {
        printf("Error: Item ID %d not found.\n", id);
        return;
    }

    printf("\nItem Found: %s", inventory[index].name);
    printf("\n1. Update Quantity");
    printf("\n2. Update Price");
    printf("\nSelect option: ");
    
    int subChoice;
    if (scanf("%d", &subChoice) != 1) {
        clearInputBuffer();
        return;
    }

    if (subChoice == 1) {
        printf("Enter New Quantity: ");
        scanf("%d", &inventory[index].quantity);
        printf("Quantity updated successfully!\n");
    } else if (subChoice == 2) {
        printf("Enter New Price: ");
        scanf("%f", &inventory[index].price);
        printf("Price updated successfully!\n");
    } else {
        printf("Invalid selection.\n");
    }
}

// Deletes an item and shifts remaining array elements leftward
void deleteItem() {
    int id;
    printf("\nEnter the Item ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID format!\n");
        clearInputBuffer();
        return;
    }

    int index = findItemIndexById(id);
    if (index == -1) {
        printf("Error: Item ID %d not found.\n", id);
        return;
    }

    // Shift elements left to fill the deleted slot
    for (int i = index; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    itemCount--;
    printf("\nSuccess: Item deleted successfully!\n");
}

// Searches for a single item by its ID
void searchItem() {
    int id;
    printf("\nEnter Item ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID format!\n");
        clearInputBuffer();
        return;
    }

    int index = findItemIndexById(id);
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    printf("\n--- Item Details ---");
    printf("\nID:       %d", inventory[index].id);
    printf("\nName:     %s", inventory[index].name);
    printf("\nQuantity: %d", inventory[index].quantity);
    printf("\nPrice:    $%.2f\n", inventory[index].price);
}

// Helper: Linearly searches the array for an ID match
int findItemIndexById(int id) {
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            return i;
        }
    }
    return -1; // Not found
}

// Helper: Prevents infinite looping errors on invalid character inputs
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}