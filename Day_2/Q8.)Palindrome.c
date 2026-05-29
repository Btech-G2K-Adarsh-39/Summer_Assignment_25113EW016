#include<stdio.h>
int main()
{
    int n,rev=0,rem,original;
    printf("Enter the value of n = ");
    scanf("%d",&n);

    original = n;

    while(n!=0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }

    if(original==rev)
    {
        printf("%d is a palindrome number\n",original);
    }
    else
    {
        printf("%d is not a palindrome number\n",original);
    }

    return 0;
    
}