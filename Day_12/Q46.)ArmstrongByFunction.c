#include <stdio.h>
#include <math.h>

// Function declaration
int isArmstrong(int num);

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    // Call the function and check the return value
    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int originalNum, remainder, originalNumForDigits;
    int digits = 0;
    int sum = 0;

    originalNum = num;
    originalNumForDigits = num;

    
    while (originalNumForDigits != 0) {
        originalNumForDigits /= 10;
        digits++;
    }

    
    while (originalNum != 0) {
        remainder = originalNum % 10;
        
        
        sum += (int)round(pow(remainder, digits)); 
        
        originalNum /= 10;
    }

    
    if (sum == num) {
        return 1; 
    } else {
        return 0;
    }
}