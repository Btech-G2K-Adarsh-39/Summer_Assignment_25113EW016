#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Define the Employee structure
typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

// Array to store records and global counter
Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

// Function declarations
void addEmployee();
void displayEmployees();
void searchEmployee();
void updateEmployee();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== MINI EMPLOYEE MANAGEMENT SYSTEM ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee Info\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                updateEmployee();
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Choose a number between 1 and 5.\n");
        }
    }
    return 0;
}

// Function to add a new employee record
void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("System full! Cannot add more employees.\n");
        return;
    }

    Employee newEmp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &newEmp.id);
    clearInputBuffer(); // Clear buffer before reading string

    // Check if ID already exists
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == newEmp.id) {
            printf("Error: An employee with ID %d already exists!\n", newEmp.id);
            return;
        }
    }

    printf("Enter Name: ");
    fgets(newEmp.name, sizeof(newEmp.name), stdin);
    newEmp.name[strcspn(newEmp.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Designation: ");
    fgets(newEmp.designation, sizeof(newEmp.designation), stdin);
    newEmp.designation[strcspn(newEmp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &newEmp.salary);

    employees[employeeCount] = newEmp;
    employeeCount++;
    printf("Employee added successfully!\n");
}

// Function to display all employee records
void displayEmployees() {
    if (employeeCount == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("----------------------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-10d %-20s %-20s %-10.2f\n", 
               employees[i].id, employees[i].name, employees[i].designation, employees[i].salary);
    }
}

// Function to search for an employee by ID
void searchEmployee() {
    if (employeeCount == 0) {
        printf("\nNo employee records to search.\n");
        return;
    }

    int searchId;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == searchId) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Designation: %s\n", employees[i].designation);
            printf("Salary: %.2f\n", employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", searchId);
}

// Function to update an existing employee's details
void updateEmployee() {
    if (employeeCount == 0) {
        printf("\nNo employee records to update.\n");
        return;
    }

    int updateId;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &updateId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == updateId) {
            printf("\nCurrent Details - Name: %s, Position: %s, Salary: %.2f\n", 
                   employees[i].name, employees[i].designation, employees[i].salary);
            
            clearInputBuffer();
            printf("Enter New Name: ");
            fgets(employees[i].name, sizeof(employees[i].name), stdin);
            employees[i].name[strcspn(employees[i].name, "\n")] = 0;

            printf("Enter New Designation: ");
            fgets(employees[i].designation, sizeof(employees[i].designation), stdin);
            employees[i].designation[strcspn(employees[i].designation, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &employees[i].salary);

            printf("Employee record updated successfully!\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", updateId);
}

// Helper function to clear leftover characters in standard input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}