#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 30

// Function prototypes
void addStudents(char names[][NAME_LENGTH], int rolls[], float marks[], int *count);
void displayStudents(char names[][NAME_LENGTH], int rolls[], float marks[], int count);
void searchStudent(char names[][NAME_LENGTH], int rolls[], float marks[], int count);

int main() {
    // Arrays to store student data
    char studentNames[MAX_STUDENTS][NAME_LENGTH]; // 2D array of strings
    int studentRolls[MAX_STUDENTS];              // 1D array for integers
    float studentMarks[MAX_STUDENTS];            // 1D array for floats
    
    int studentCount = 0; // Tracks number of records added
    int choice;

    do {
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student Records\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // Clears the newline character from the input buffer

        switch (choice) {
            case 1:
                addStudents(studentNames, studentRolls, studentMarks, &studentCount);
                break;
            case 2:
                displayStudents(studentNames, studentRolls, studentMarks, studentCount);
                break;
            case 3:
                searchStudent(studentNames, studentRolls, studentMarks, studentCount);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add new student records into arrays
void addStudents(char names[][NAME_LENGTH], int rolls[], float marks[], int *count) {
    int num, i;
    printf("\nHow many students do you want to add? ");
    scanf("%d", &num);
    getchar(); // Clear buffer

    if (*count + num > MAX_STUDENTS) {
        printf("Error: Cannot exceed maximum capacity of %d students.\n", MAX_STUDENTS);
        return;
    }

    for (i = 0; i < num; i++) {
        printf("\nEnter details for Student %d:\n", *count + 1);
        
        printf("Enter Name: ");
        fgets(names[*count], NAME_LENGTH, stdin);
        // Remove trailing newline character added by fgets
        names[*count][strcspn(names[*count], "\n")] = '\0';

        printf("Enter Roll Number: ");
        scanf("%d", &rolls[*count]);

        printf("Enter Marks: ");
        scanf("%float", &marks[*count]);
        getchar(); // Clear buffer

        (*count)++; // Increment total count via pointer
    }
    printf("\nRecords added successfully!\n");
}

// Function to loop through arrays and display values
void displayStudents(char names[][NAME_LENGTH], int rolls[], float marks[], int count) {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n-------------------------------------------------\n");
    printf("%-5s %-20s %-10s %-5s\n", "S.No", "Name", "Roll No", "Marks");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-10d %-5.2f\n", i + 1, names[i], rolls[i], marks[i]);
    }
    printf("-------------------------------------------------\n");
}

// Function to search record using string comparison
void searchStudent(char names[][NAME_LENGTH], int rolls[], float marks[], int count) {
    if (count == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    char searchName[NAME_LENGTH];
    int found = 0;

    printf("\nEnter the name of the student to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < count; i++) {
        // strcmp returns 0 if strings match exactly
        if (strcmp(names[i], searchName) == 0) {
            printf("\nRecord Found!");
            printf("\nName: %s\nRoll No: %d\nMarks: %.2f\n", names[i], rolls[i], marks[i]);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("\nStudent with name '%s' not found.\n", searchName);
    }
}