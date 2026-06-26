#include <stdio.h>
#include <ctype.h>

#define TOTAL_QUESTIONS 4

// Structure to bundle question data together
typedef struct {
    char question_text[256];
    char options[4][128];
    char correct_option;
} QuizQuestion;

int main() {
    // Initializing the array of quiz questions
    QuizQuestion quiz[TOTAL_QUESTIONS] = {
        {
            "Which data type is used to store a single character in C?",
            {"A. int", "B. float", "C. char", "D. double"},
            'C'
        },
        {
            "What is the correct format specifier for printing an integer?",
            {"A. %f", "B. %d", "C. %c", "D. %s"},
            'B'
        },
        {
            "Which of the following loops guarantees execution at least once?",
            {"A. for", "B. while", "C. do-while", "D. none of these"},
            'C'
        },
        {
            "What keyword is used to return a value from a function?",
            {"A. break", "B. return", "C. continue", "D. void"},
            'B'
        }
    };

    int score = 0;
    char user_answer;

    printf("=========================================\n");
    printf("     WELCOME TO THE C PROGRAMMING QUIZ    \n");
    printf("=========================================\n\n");

    // Loop through each question
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].question_text);
        
        // Print the 4 options
        for (int j = 0; j < 4; j++) {
            printf("  %s\n", quiz[i].options[j]);
        }

        // Prompt user and read input securely
        printf("Your answer (A, B, C, or D): ");
        // The space before %c skips any leftover newline characters in the input buffer
        scanf(" %c", &user_answer);

        // Convert input to uppercase to handle lowercase answers gracefully
        user_answer = toupper(user_answer);

        // Evaluate the answer
        if (user_answer == quiz[i].correct_option) {
            printf("Result: Correct!\n\n");
            score++;
        } else {
            printf("Result: Wrong. The correct answer was %c.\n\n", quiz[i].correct_option);
        }
        printf("-----------------------------------------\n");
    }

    // Final Performance Summary
    printf("\n=========================================\n");
    printf("               QUIZ OVER!                \n");
    printf("=========================================\n");
    printf("Your Total Score: %d out of %d\n", score, TOTAL_QUESTIONS);
    
    float percentage = ((float)score / TOTAL_QUESTIONS) * 100;
    printf("Percentage: %.2f%%\n", percentage);
    printf("=========================================\n");

    return 0;
}