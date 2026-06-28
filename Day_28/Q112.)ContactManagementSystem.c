#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.txt"

// Structure to define contact details
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// Function Prototypes
void addContact();
void viewContacts();
void searchContact();
void deleteContact();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== CONTACT MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose between 1 and 5.\n");
        }
    }
    return 0;
}

// Function to safely clear standard input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to add a new contact to the file
void addContact() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Contact newContact;

    printf("Enter Name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Phone Number: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(newContact.email, sizeof(newContact.email), stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0';

    // Write formatted data to file
    fprintf(file, "%s,%s,%s\n", newContact.name, newContact.phone, newContact.email);
    fclose(file);

    printf("Contact added successfully!\n");
}

// Function to view all stored contacts
void viewContacts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No contacts found or file does not exist yet.\n");
        return;
    }

    Contact c;
    char line[150];
    int count = 1;

    printf("\n---------------------------------------------------------------\n");
    printf("%-5s %-20s %-15s %-25s\n", "S.No", "Name", "Phone", "Email");
    printf("---------------------------------------------------------------\n");

    while (fgets(line, sizeof(line), file)) {
        // Parse CSV format from text file
        sscanf(line, "%[^,],%[^,],%[^\n]", c.name, c.phone, c.email);
        printf("%-5d %-20s %-15s %-25s\n", count++, c.name, c.phone, c.email);
    }

    printf("---------------------------------------------------------------\n");
    fclose(file);
}

// Function to search for a contact by name
void searchContact() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No contacts found.\n");
        return;
    }

    char searchName[50];
    char line[150];
    Contact c;
    int found = 0;

    printf("Enter name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%[^,],%[^\n]", c.name, c.phone, c.email);
        
        // Case-insensitive comparison can be done with strcasecmp if available, using strstr here
        if (strstr(c.name, searchName) != NULL) {
            if (!found) {
                printf("\nMatch Found:\n");
                printf("---------------------------------------------------------------\n");
                printf("%-20s %-15s %-25s\n", "Name", "Phone", "Email");
                printf("---------------------------------------------------------------\n");
            }
            printf("%-20s %-15s %-25s\n", c.name, c.phone, c.email);
            found = 1;
        }
    }

    if (!found) {
        printf("No contact found with the name '%s'.\n", searchName);
    } else {
        printf("---------------------------------------------------------------\n");
    }

    fclose(file);
}

// Function to delete a contact by name
void deleteContact() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No contacts found.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("System error. Unable to perform deletion.\n");
        fclose(file);
        return;
    }

    char deleteName[50];
    char line[150];
    Contact c;
    int found = 0;

    printf("Enter the exact name of the contact to delete: ");
    fgets(deleteName, sizeof(deleteName), stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%[^,],%[^\n]", c.name, c.phone, c.email);
        
        // If it matches the name to delete, skip writing it to temp file
        if (strcmp(c.name, deleteName) == 0) {
            found = 1; // Mark that we found and skipped it
        } else {
            fprintf(tempFile, "%s,%s,%s\n", c.name, c.phone, c.email);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);        // Delete original file
        rename("temp.txt", FILE_NAME); // Rename temp file to original name
        printf("Contact '%s' deleted successfully.\n", deleteName);
    } else {
        remove("temp.txt"); // Clean up temporary file
        printf("Contact '%s' not found.\n", deleteName);
    }
}