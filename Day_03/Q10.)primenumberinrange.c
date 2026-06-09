#include<stdio.h>

int isprime(int num)
{
    if(num<=1){
        return 0;
    }
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int lowerbound,upperbound;

    printf("Enter lowerbound of the range :");
    scanf("%d",&lowerbound);

    printf("Enter upperbound of the range :");
    scanf("%d",&upperbound);

    printf("\n Prime number between %d and %d are :\n",lowerbound,upperbound);

    int found = 0;
    for(int i = lowerbound; i<= upperbound; i++){
        if(isprime(i)){
            printf("%d\n",i);
            found = 1;
        }
    }
    
    if(!found){
        printf("None found");
    }

    printf("\n");

    return 0;

}