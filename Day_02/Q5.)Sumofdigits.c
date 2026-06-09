#include<stdio.h>
int main()
{
    int n,sum,rem;
    printf("Enter the value of a n = ");
    scanf("%d",&n);

    sum = 0;
    while(n!=0)
    {
        rem = n % 10;
        sum = sum + rem;
        n = n / 10;

    }

    printf("Sum of digits of given number is %d",sum);

    return 0;

}