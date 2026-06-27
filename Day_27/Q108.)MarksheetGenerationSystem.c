#include <stdio.h>
#include <string.h>

#define NUM_SUBJECTS 5

// Structure to hold student data
struct Student {
    int rollNumber;
    char name[50];
    char className[20];
    int marks[NUM_SUBJECTS];
    int totalMarks;
    float percentage;
    char grade;
    char status[5];
};

// Subject name definitions
const char* subjects[NUM_SUBJECTS] = {
    "Mathematics", 
    "Physics", 
    "Chemistry", 
    "English", 
    "Computer Science"
};

// Function prototypes
void calculateResult(struct Student *s);
void generateMarksheet(struct Student s);

int main() {
    struct Student s1;
    
    printf("==========================================\n");
    printf("   STUDENT MARKSHEET GENERATION SYSTEM    \n");
    printf("==========================================\n\n");
    
    // Collecting Student Demographic Information
    printf("Enter Student Roll Number: ");
    scanf("%d", &s1.rollNumber);
    getchar(); // Clear newline buffer trailing from scanf
    
    printf("Enter Student Full Name: ");
    fgets(s1.name, sizeof(s1.name), stdin);
    s1.name[strcspn(s1.name, "\n")] = 0; // Strip trailing newline character
    
    printf("Enter Class/Standard: ");
    fgets(s1.className, sizeof(s1.className), stdin);
    s1.className[strcspn(s1.className, "\n")] = 0; // Strip trailing newline character
    
    // Collecting Subject Marks
    printf("\n--- Enter Marks (out of 100) ---\n");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        do {
            printf("%s: ", subjects[i]);
            scanf("%d", &s1.marks[i]);
            if (s1.marks[i] < 0 || s1.marks[i] > 100) {
                printf("Error: Marks must be between 0 and 100. Try again.\n");
            }
        } while (s1.marks[i] < 0 || s1.marks[i] > 100);
    }
    
    // Process core processing operations
    calculateResult(&s1);
    
    // Display the final output layout
    generateMarksheet(s1);
    
    return 0;
}

// Function to calculate aggregate totals, percentage, metrics, and grades
void calculateResult(struct Student *s) {
    s->totalMarks = 0;
    int failedSubjects = 0;
    
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        s->totalMarks += s->marks[i];
        // Mark student as failed in a subject if score is under 33
        if (s->marks[i] < 33) {
            failedSubjects++;
        }
    }
    
    s->percentage = (float)s->totalMarks / NUM_SUBJECTS;
    
    // Grade Assessment Logic
    if (s->percentage >= 90) s->grade = 'A';
    else if (s->percentage >= 75) s->grade = 'B';
    else if (s->percentage >= 50) s->grade = 'C';
    else if (s->percentage >= 33) s->grade = 'D';
    else s->grade = 'F';
    
    // Status Assessment Logic
    if (failedSubjects > 0) {
        strcpy(s->status, "FAIL");
    } else {
        strcpy(s->status, "PASS");
    }
}

// Function to print out the final report card presentation view
void generateMarksheet(struct Student s) {
    printf("\n\n");
    printf("=========================================================\n");
    printf("                NATIONAL HIGH SCHOOL REPORT              \n");
    printf("=========================================================\n");
    printf(" Roll No: %-10d | Student Name: %-20s\n", s.rollNumber, s.name);
    printf(" Class:   %-10s | Academic Year: 2025-2026\n", s.className);
    printf("---------------------------------------------------------\n");
    printf(" %-25s | %-15s | %-10s\n", "SUBJECT NAME", "MAX MARKS", "OBTAINED");
    printf("---------------------------------------------------------\n");
    
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf(" %-25s | %-15d | %-10d\n", subjects[i], 100, s.marks[i]);
    }
    
    printf("---------------------------------------------------------\n");
    printf(" Aggregate Total Marks : %d / %d\n", s.totalMarks, NUM_SUBJECTS * 100);
    printf(" Final Percentage      : %.2f%%\n", s.percentage);
    printf(" Assigned Grade        : %c\n", s.grade);
    printf(" Overall Status        : %s\n", s.status);
    printf("=========================================================\n");
}