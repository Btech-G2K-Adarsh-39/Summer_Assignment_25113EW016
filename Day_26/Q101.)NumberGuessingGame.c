#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, guess;
    int attempts = 0;

    // Seed the random number generator with the current system time
    srand(time(NULL));

    // Generate a random number between 1 and 100
    secret_number = (rand() % 100) + 1;

    printf("===================================\n");
    printf("    WELCOME TO THE GUESSING GAME   \n");
    printf("===================================\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("Can you guess what it is?\n\n");

    // Loop until the player guesses the correct number
    do {
        printf("Enter your guess: ");
        
        // Validate if the input is an integer
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            
            // Clear the invalid input buffer
            while (getchar() != '\n');
            continue;
        }

        attempts++;

        // Provide feedback based on the player's guess
        if (guess > secret_number) {
            printf("Too high! Try a lower number.\n\n");
        } else if (guess < secret_number) {
            printf("Too low! Try a higher number.\n\n");
        } else {
            printf("\n🎉 CONGRATULATIONS! You found it! 🎉\n");
            printf("The secret number was %d.\n", secret_number);
            printf("It took you exactly %d attempts.\n", attempts);
        }

    } while (guess != secret_number);

    return 0;
}