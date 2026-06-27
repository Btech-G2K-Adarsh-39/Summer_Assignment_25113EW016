#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Employee structure
struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};

// Function declarations
void addEmployee();
void displayEmployees();
void searchEmployee();
void modifyEmployee();
void deleteEmployee();

const char *FILE_NAME = "employees.dat";

int main() {
    int choice;

    while (1) {
        printf("\n====================================");
        printf("\n     EMPLOYEE MANAGEMENT SYSTEM     ");
        printf("\n====================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Records");
        printf("\n3. Search Employee Record");
        printf("\n4. Modify Employee Record");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: modifyEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("\nExiting program. Thank you!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please choose between 1 and 6.\n");
        }
    }
    return 0;
}

// 1. Add a new employee record to the file
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Open in append binary mode
    if (fp == NULL) {
        printf("\nError opening file!");
        return;
    }

    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // Clear the input buffer newline

    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove newline character from fgets

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(struct Employee), 1, fp);
    fclose(fp);

    printf("\nRecord added successfully!\n");
}

// 2. Display all employee records saved in the file
void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb"); // Open in read binary mode
    if (fp == NULL) {
        printf("\nNo records found! Add some records first.\n");
        return;
    }

    struct Employee emp;
    printf("\n=================================================================");
    printf("\n%-10s %-20s %-20s %-10s", "ID", "Name", "Designation", "Salary");
    printf("\n=================================================================");
    
    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        printf("\n%-10d %-20s %-20s $%-9.2f", emp.id, emp.name, emp.designation, emp.salary);
    }
    printf("\n=================================================================\n");
    fclose(fp);
}

// 3. Search for a specific employee by ID
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int searchId, found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        if (emp.id == searchId) {
            found = 1;
            printf("\nRecord Found!");
            printf("\nID: %d", emp.id);
            printf("\nName: %s", emp.name);
            printf("\nDesignation: %s", emp.designation);
            printf("\nSalary: $%.2f\n", emp.salary);
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
    fclose(fp);
}

// 4. Modify an existing employee record
void modifyEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb+"); // Open in read/write binary mode
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int targetId, found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to modify: ");
    scanf("%d", &targetId);

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        if (emp.id == targetId) {
            found = 1;
            getchar(); // Clear buffer

            printf("\nEnter New Name: ");
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = 0;

            printf("Enter New Designation: ");
            fgets(emp.designation, sizeof(emp.designation), stdin);
            emp.designation[strcspn(emp.designation, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);

            // Move the file pointer back to the beginning of the current record block
            fseek(fp, -sizeof(struct Employee), SEEK_CUR);
            fwrite(&emp, sizeof(struct Employee), 1, fp);
            printf("\nRecord updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", targetId);
    }
    fclose(fp);
}

// 5. Delete an employee record using a temporary file transfer
void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("\nError opening temporary file!");
        fclose(fp);
        return;
    }

    int targetId, found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &targetId);

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        if (emp.id == targetId) {
            found = 1; // Skip writing this record to the temp file
        } else {
            fwrite(&emp, sizeof(struct Employee), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILE_NAME);         // Remove original database file
        rename("temp.dat", FILE_NAME); // Rename temp file to replace the original
        printf("\nRecord deleted successfully!\n");
    } else {
        remove("temp.dat"); // Clean up the temp file if record wasn't found
        printf("\nEmployee with ID %d not found.\n", targetId);
    }
}