#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Define the structure for a student record
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

// Global array to store records and a counter to track the current total
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting program. Goodbye!\n"); return 0;
            default: printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// 1. Add a new student record
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("System full! Cannot add more student records.\n");
        return;
    }

    Student newStudent;
    printf("\nEnter Student ID: ");
    scanf("%d", &newStudent.id);

    // Check if ID already exists
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == newStudent.id) {
            printf("Error: A student with ID %d already exists.\n", newStudent.id);
            return;
        }
    }

    printf("Enter Student Name: ");
    getchar(); // Clear the newline character left in buffer
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Student Age: ");
    scanf("%d", &newStudent.age);

    printf("Enter Student GPA: ");
    scanf("%f", &newStudent.gpa);

    students[studentCount] = newStudent;
    studentCount++;
    printf("Student record added successfully!\n");
}

// 2. Display all records
void displayStudents() {
    if (studentCount == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n%-10s %-25s %-5s %-5s\n", "ID", "Name", "Age", "GPA");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-25s %-5d %-5.2f\n", students[i].id, students[i].name, students[i].age, students[i].gpa);
    }
}

// 3. Search student by ID
void searchStudent() {
    if (studentCount == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int searchId;
    printf("\nEnter Student ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchId) {
            printf("\nRecord Found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nGPA: %.2f\n", students[i].id, students[i].name, students[i].age, students[i].gpa);
            return;
        }
    }
    printf("Student with ID %d not found.\n", searchId);
}

// 4. Update an existing record
void updateStudent() {
    if (studentCount == 0) {
        printf("\nNo records available to update.\n");
        return;
    }

    int updateId;
    printf("\nEnter Student ID to update: ");
    scanf("%d", &updateId);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == updateId) {
            printf("\nExisting details: Name: %s, Age: %d, GPA: %.2f\n", students[i].name, students[i].age, students[i].gpa);
            
            printf("Enter New Name: ");
            getchar(); // Clear buffer
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter New Age: ");
            scanf("%d", &students[i].age);

            printf("Enter New GPA: ");
            scanf("%f", &students[i].gpa);

            printf("Record updated successfully!\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", updateId);
}

// 5. Delete a student record
void deleteStudent() {
    if (studentCount == 0) {
        printf("\nNo records available to delete.\n");
        return;
    }

    int deleteId;
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == deleteId) {
            // Shift all subsequent elements back by one index
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", deleteId);
}