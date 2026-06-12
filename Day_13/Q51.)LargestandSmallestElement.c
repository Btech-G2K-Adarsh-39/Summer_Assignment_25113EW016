#include <stdio.h>

void getSmallLarge(int arr[], int n)
{
    int smallest, largest;
    
    smallest = largest = arr[0];
    
    for(int i = 1; i < n ;i++){
        
        // finding smallest here
        if(arr[i] < smallest) smallest = arr[i]; // finding largest here
 if(arr[i] > largest) largest = arr[i]; 
        
    } 
    printf("Smallest: %d\n",smallest);
    printf("Largest: %d", largest); 
    
} 
int main() 
{ 
    int arr[] = {25, 40, 35, 20, 10, 80}; 
int len = sizeof(arr)/sizeof(arr[0]);
getSmallLarge(arr, len);

}