#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 10

// Structure to hold individual seat details
typedef struct {
    int seatNumber;
    int isBooked;
    char passengerName[50];
} Seat;

// Global 2D array representing the theater/bus seating arrangement
Seat layout[ROWS][COLS];

// Function declarations
void initializeSeats();
void displaySeats();
void bookTicket();
void cancelTicket();
void clearInputBuffer();

int main() {
    int choice;
    initializeSeats();

    while (1) {
        printf("\n=================================");
        printf("\n      TICKET BOOKING SYSTEM      ");
        printf("\n=================================");
        printf("\n1. View Available Seats");
        printf("\n2. Book a Ticket");
        printf("\n3. Cancel a Ticket");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                printf("\nThank you for using our booking system!\n");
                exit(0);
            default:
                printf("\nInvalid selection! Please choose an option between 1 and 4.\n");
        }
    }
    return 0;
}

// Assign unique seat numbers and mark all seats as empty initially
void initializeSeats() {
    int count = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            layout[i][j].seatNumber = count++;
            layout[i][j].isBooked = 0;
            strcpy(layout[i][j].passengerName, "");
        }
    }
}

// Display visual matrix layout of the seats
void displaySeats() {
    printf("\n--- SEATING ARRANGEMENT ---");
    printf("\n[XX] = Booked seat | Numbers = Available seats\n\n");
    
    for (int i = 0; i < ROWS; i++) {
        printf("Row %d:  ", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (layout[i][j].isBooked == 1) {
                printf("[XX] ");
            } else {
                printf("[%02d] ", layout[i][j].seatNumber);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Reserve a seat by mapping the input number back to row/column indexes
void bookTicket() {
    int targetSeat;
    displaySeats();
    
    printf("Enter the seat number you want to book (1-%d): ", ROWS * COLS);
    if (scanf("%d", &targetSeat) != 1 || targetSeat < 1 || targetSeat > (ROWS * COLS)) {
        printf("\nError: Invalid seat number!\n");
        clearInputBuffer();
        return;
    }

    // Mathematical mapping from seat number to 2D array indexes
    int r = (targetSeat - 1) / COLS;
    int c = (targetSeat - 1) % COLS;

    if (layout[r][c].isBooked == 1) {
        printf("\nSorry, seat %d is already booked by %s.\n", targetSeat, layout[r][c].passengerName);
    } else {
        printf("Enter passenger name: ");
        clearInputBuffer(); // Prevent trailing newline bugs
        fgets(layout[r][c].passengerName, sizeof(layout[r][c].passengerName), stdin);
        
        // Remove trailing newline character left behind by fgets
        layout[r][c].passengerName[strcspn(layout[r][c].passengerName, "\n")] = '\0';
        
        layout[r][c].isBooked = 1;
        printf("\nSuccess! Seat %d has been successfully booked.\n", targetSeat);
    }
}

// Free up a booked seat and reset passenger information
void cancelTicket() {
    int targetSeat;
    printf("\nEnter the seat number you want to cancel (1-%d): ", ROWS * COLS);
    if (scanf("%d", &targetSeat) != 1 || targetSeat < 1 || targetSeat > (ROWS * COLS)) {
        printf("\nError: Invalid seat number!\n");
        clearInputBuffer();
        return;
    }

    int r = (targetSeat - 1) / COLS;
    int c = (targetSeat - 1) % COLS;

    if (layout[r][c].isBooked == 0) {
        printf("\nThis seat is not currently booked.\n");
    } else {
        printf("\nBooking for seat %d under the name '%s' has been canceled.\n", targetSeat, layout[r][c].passengerName);
        layout[r][c].isBooked = 0;
        strcpy(layout[r][c].passengerName, "");
    }
}

// Flush residual data left in stdin to prevent program skip errors
void clearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}