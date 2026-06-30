#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Define the book structure
struct Book {
    int id;
    char title[100];
    char author[50];
    int quantity;
};

// Global variables to track the library array
struct Book library[MAX_BOOKS];
int bookCount = 0;

// Function declarations
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n========================================\n");
        printf("       MINI LIBRARY MANAGEMENT SYSTEM   \n");
        printf("========================================\n");
        printf("1. Add a New Book\n");
        printf("2. Display All Available Books\n");
        printf("3. Search for a Book by ID\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Exit System\n");
        printf("========================================\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid numeric input. Please try again.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("\nExiting the system. Thank you for using the library!\n");
                exit(0);
            default:
                printf("\n[Error] Choice out of range. Enter a number between 1 and 6.\n");
        }
    }
    return 0;
}

// Safely flush leftover newline characters from standard input
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Add a book to the library array
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\n[Error] Library inventory is full! Cannot add more books.\n");
        return;
    }

    struct Book newBook;
    
    printf("\nEnter Book ID (Integer): ");
    if (scanf("%d", &newBook.id) != 1) {
        printf("[Error] Invalid ID format.\n");
        clearInputBuffer();
        return;
    }

    // Check if the ID already exists
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == newBook.id) {
            printf("[Error] A book with ID %d already exists.\n", newBook.id);
            return;
        }
    }

    clearInputBuffer(); // Clear buffer before reading strings

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Strip trailing newline

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Strip trailing newline

    printf("Enter Total Quantity: ");
    if (scanf("%d", &newBook.quantity) != 1 || newBook.quantity < 0) {
        printf("[Error] Invalid stock amount.\n");
        clearInputBuffer();
        return;
    }

    library[bookCount] = newBook;
    bookCount++;
    printf("\n[Success] Book recorded successfully!\n");
}

// 2. Display all cataloged records
void displayBooks() {
    if (bookCount == 0) {
        printf("\nThe library registry is currently empty.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-10s\n", "Book ID", "Title", "Author", "In Stock");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-30s %-25s %-10d\n", 
               library[i].id, library[i].title, library[i].author, library[i].quantity);
    }
}

// 3. Query a specific record by ID
void searchBook() {
    if (bookCount == 0) {
        printf("\nThe library registry is currently empty.\n");
        return;
    }

    int searchId;
    printf("\nEnter the Book ID to look up: ");
    if (scanf("%d", &searchId) != 1) {
        printf("[Error] Invalid input.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("\n--- Match Found ---\n");
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Available Stock: %d\n", library[i].quantity);
            return;
        }
    }
    printf("\n[Notice] No book found matching ID %d.\n", searchId);
}

// 4. Decrease available stock by 1 when issued
void issueBook() {
    int targetId;
    printf("\nEnter the Book ID to issue: ");
    if (scanf("%d", &targetId) != 1) {
        printf("[Error] Invalid input.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == targetId) {
            if (library[i].quantity > 0) {
                library[i].quantity--;
                printf("\n[Success] One copy of \"%s\" has been issued.\n", library[i].title);
            } else {
                printf("\n[Notice] Checked out failed. No physical copies left in stock.\n");
            }
            return;
        }
    }
    printf("\n[Error] Book record not found.\n");
}

// 5. Increase available stock by 1 when returned
void returnBook() {
    int targetId;
    printf("\nEnter the Book ID to return: ");
    if (scanf("%d", &targetId) != 1) {
        printf("[Error] Invalid input.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == targetId) {
            library[i].quantity++;
            printf("\n[Success] One copy of \"%s\" has been returned to stock.\n", library[i].title);
            return;
        }
    }
    printf("\n[Error] Book record not found.\n");
}