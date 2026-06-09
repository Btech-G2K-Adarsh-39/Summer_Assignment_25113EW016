#include <stdio.h>

int main() {
    int decimal, quotient, remainder;
    int binary[32];  
    int i;

    
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    quotient = decimal;
    i = 0;

    
    for (; quotient > 0; i++) {
        remainder = quotient % 2;
        binary[i] = remainder;
        quotient = quotient / 2;
    }

    
    printf("Binary equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");

    return 0;
}


