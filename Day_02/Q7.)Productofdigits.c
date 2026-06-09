#include<stdio.h>
int main()
{
    int n,rem,product=1;
    printf("Enter the value of n = ");
    scanf("%d",&n);

    while(n!=0)
    {
        rem = n % 10;
        product = product * rem;
        n = n / 10;
    }

    printf("Product of digits in a number is %d",product);
    return 0;

}