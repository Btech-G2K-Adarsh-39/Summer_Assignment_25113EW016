#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to hold book metadata
struct Book {
    int id;
    char title[100];
    char author[50];
    int available; // 1 for True, 0 for False (Issued)
};

// Global library storage and counter
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
        printf("\n=================================");
        printf("\n    LIBRARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
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
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option! Please pick a choice between 1 and 6.\n");
        }
    }
    return 0;
}

// 1. Add a new book to the library array
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nError: Library storage is full!\n");
        return;
    }

    struct Book newBook;
    printf("\nEnter Unique Book ID (Integer): ");
    scanf("%d", &newBook.id);
    clearInputBuffer(); // Prevent trailing newline from breaking subsequent string inputs

    // Basic validation to avoid duplicate IDs
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == newBook.id) {
            printf("\nError: A book with ID %d already exists!\n", newBook.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Strip trailing newline character

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    newBook.available = 1; // Default status is available

    library[bookCount] = newBook;
    bookCount++;

    printf("\nSuccess: Book added successfully!\n");
}

// 2. Display all records in structured form
void displayBooks() {
    if (bookCount == 0) {
        printf("\nNo books registered in the library yet.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-15s", "ID", "Title", "Author", "Status");
    printf("\n--------------------------------------------------------------------------------");
    for (int i = 0; i < bookCount; i++) {
        printf("\n%-10d %-30s %-25s %-15s", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].available ? "Available" : "Issued");
    }
    printf("\n--------------------------------------------------------------------------------\n");
}

// 3. Search for a specific book by ID
void searchBook() {
    if (bookCount == 0) {
        printf("\nThe library database is empty.\n");
        return;
    }

    int searchId;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("\n--- Book Found ---");
            printf("\nID: %d", library[i].id);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nStatus: %s\n", library[i].available ? "Available" : "Issued");
            return;
        }
    }
    printf("\nBook with ID %d not found.\n", searchId);
}

// 4. Update status to issued (0)
void issueBook() {
    int issueId;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &issueId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == issueId) {
            if (library[i].available == 1) {
                library[i].available = 0; // Mark as issued
                printf("\nSuccess: Book '%s' has been successfully issued.\n", library[i].title);
            } else {
                printf("\nStatus: This book is already issued to someone else.\n");
            }
            return;
        }
    }
    printf("\nBook with ID %d does not exist.\n", issueId);
}

// 5. Update status back to available (1)
void returnBook() {
    int returnId;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &returnId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == returnId) {
            if (library[i].available == 0) {
                library[i].available = 1; // Mark as available
                printf("\nSuccess: Book '%s' has been safely returned to inventory.\n", library[i].title);
            } else {
                printf("\nStatus: Error! This book is already available in the inventory.\n");
            }
            return;
        }
    }
    printf("\nBook with ID %d does not belong to this library.\n", returnId);
}

// Helper function to flush leftover characters from stdin
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}