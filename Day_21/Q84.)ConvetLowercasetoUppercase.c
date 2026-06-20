#include <stdio.h>
#include <ctype.h> // Required for toupper()

int main() {
    char str[100];
    int i = 0;

    printf("Enter a string in lowercase: ");
    // Safely read a string including spaces
    fgets(str, sizeof(str), stdin); 

    // Loop through the string until the null terminator
    while (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }

    printf("Uppercase string: %s", str);

    return 0;
}