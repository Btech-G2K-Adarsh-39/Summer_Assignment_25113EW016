#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "salary_records.dat"

// Define Employee Structure
struct Employee {
    int id;
    char name[50];
    char designation[30];
    float basic_salary;
    float allowance;
    float deduction;
    float gross_salary;
    float net_salary;
};

// Function Prototypes
void addEmployee();
void displayAll();
void searchEmployee();
void generatePayslip();
void calculateSalary(struct Employee *emp);

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    SALARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Records");
        printf("\n3. Search Employee by ID");
        printf("\n4. Generate Salary Slip");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                generatePayslip();
                break;
            case 5:
                printf("\nThank you for using the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Calculate Gross and Net Salary automatically
void calculateSalary(struct Employee *emp) {
    // Standard industry formulas
    emp->gross_salary = emp->basic_salary + emp->allowance;
    emp->net_salary = emp->gross_salary - emp->deduction;
}

// Add a new record to the binary file
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        printf("\nError opening file!");
        return;
    }

    struct Employee emp;
    
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // Clear newline buffer

    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basic_salary);

    printf("Enter Allowances (HRA/DA): ");
    scanf("%f", &emp.allowance);

    printf("Enter Deductions (Tax/PF): ");
    scanf("%f", &emp.deduction);

    calculateSalary(&emp);

    fwrite(&emp, sizeof(struct Employee), 1, fp);
    fclose(fp);

    printf("\nRecord added successfully!\n");
}

// Display all stored records in a tabular layout
void displayAll() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found. Please add a record first.");
        return;
    }

    struct Employee emp;
    printf("\n%-5s %-20s %-15s %-12s %-12s %-12s", "ID", "Name", "Designation", "Basic", "Deduction", "Net Salary");
    printf("\n---------------------------------------------------------------------------------");

    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        printf("\n%-5d %-20s %-15s %-12.2f %-12.2f %-12.2f", 
               emp.id, emp.name, emp.designation, emp.basic_salary, emp.deduction, emp.net_salary);
    }
    printf("\n---------------------------------------------------------------------------------\n");
    fclose(fp);
}

// Search for a specific employee profile
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.");
        return;
    }

    int searchId, found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to Search: ");
    scanf("%d", &searchId);

    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        if (emp.id == searchId) {
            found = 1;
            printf("\n--- Record Found ---");
            printf("\nID: %d", emp.id);
            printf("\nName: %s", emp.name);
            printf("\nDesignation: %s", emp.designation);
            printf("\nBasic Salary: $%.2f", emp.basic_salary);
            printf("\nAllowances: $%.2f", emp.allowance);
            printf("\nDeductions: $%.2f", emp.deduction);
            printf("\nGross Salary: $%.2f", emp.gross_salary);
            printf("\nNet Salary: $%.2f\n", emp.net_salary);
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
    fclose(fp);
}

// Format and print a personalized salary slip
void generatePayslip() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.");
        return;
    }

    int targetId, found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to generate payslip: ");
    scanf("%d", &targetId);

    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        if (emp.id == targetId) {
            found = 1;
            printf("\n==================================================");
            printf("\n                SALARY PAYSLIP                   ");
            printf("\n==================================================");
            printf("\n Emp ID      : %-15d Designation: %s", emp.id, emp.designation);
            printf("\n Name        : %-15s", emp.name);
            printf("\n--------------------------------------------------");
            printf("\n EARNINGS                      DEDUCTIONS         ");
            printf("\n--------------------------------------------------");
            printf("\n Basic Pay   : $%-14.2f Tax / PF   : $%.2f", emp.basic_salary, emp.deduction);
            printf("\n Allowances  : $%-14.2f", emp.allowance);
            printf("\n--------------------------------------------------");
            printf("\n GROSS PAY   : $%-14.2f TOTAL DED. : $%.2f", emp.gross_salary, emp.deduction);
            printf("\n--------------------------------------------------");
            printf("\n NET TAKE-HOME: $%.2f", emp.net_salary);
            printf("\n==================================================\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee record not found.\n");
    }
    fclose(fp);
}