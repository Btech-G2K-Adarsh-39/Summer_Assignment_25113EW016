#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Structure representing a single student record
struct Student {
    int rollNumber;
    char name[NAME_LENGTH];
    float marks;
};

// Function prototypes
void addStudent(struct Student students[], int *count);
void displayStudents(const struct Student students[], int count);
void searchStudent(const struct Student students[], int count);

int main() {
    struct Student database[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        // Read input and check for valid integer entry
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(database, &studentCount);
                break;
            case 2:
                displayStudents(database, studentCount);
                break;
            case 3:
                searchStudent(database, studentCount);
                break;
            case 4:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a new student record
void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Error: Database is full! Cannot add more students.\n");
        return;
    }

    struct Student newStudent;
    
    printf("\nEnter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    
    // Check if roll number already exists
    for (int i = 0; i < *count; i++) {
        if (students[i].rollNumber == newStudent.rollNumber) {
            printf("Error: A student with Roll Number %d already exists!\n", newStudent.rollNumber);
            return;
        }
    }

    printf("Enter Student Name: ");
    while (getchar() != '\n'); // Clear the newline left over by previous scanf
    fgets(newStudent.name, NAME_LENGTH, stdin);
    
    // Remove the newline character caught by fgets
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &newStudent.marks);

    // Save the student to the array and increment count
    students[*count] = newStudent;
    (*count)++;
    
    printf("Record added successfully!\n");
}

// Function to print all student records
void displayStudents(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n%-12s %-25s %-6s\n", "Roll Number", "Name", "Marks");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-12d %-25s %-6.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
    }
}

// Function to search for a specific student using linear search
void searchStudent(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    int targetRoll;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &targetRoll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == targetRoll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name:        %s\n", students[i].name);
            printf("Marks:       %.2f\n", students[i].marks);
            found = 1;
            break; // Stop loop once match is found
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", targetRoll);
    }
}