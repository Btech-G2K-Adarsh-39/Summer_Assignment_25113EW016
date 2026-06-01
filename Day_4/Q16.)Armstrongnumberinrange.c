#include <stdio.h>

void main(){
    int num, r, sum, temp; 
    int stno, enno; 

    printf("Input starting number of range: "); 
    scanf("%d", &stno); 

    printf("Input ending number of range : ");
    scanf("%d", &enno); 

    printf("Armstrong numbers in given range are: "); 

    for(num = stno; num <= enno; num++){ 
        temp = num; 
        sum = 0; // Initialize 'sum' to zero.

        while(temp != 0){ // Start a loop to extract digits from 'temp'.
            r = temp % 10; // Get the last digit of 'temp'.
            temp = temp / 10; // Remove the last digit from 'temp'.
            sum = sum + (r * r * r); 
        }

        if(sum == num) // 
            printf("%d ", num); 
    }

    printf("\n");
}