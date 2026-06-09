#include<stdio.h>
int main()
{
    int n,count =0;
    printf("Enter the value of n = ");
    scanf("%d",&n);

    while(n>0)
    {
        count++;
        n=n/10;
    }

    printf("Count digits in a number is = %d",count);
    return 0;

}