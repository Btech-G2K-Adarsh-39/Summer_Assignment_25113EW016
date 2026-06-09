#include<stdio.h>
int main()
{
    int n,first=0,second=1,next;
    printf("Enter the value of n = ");
    scanf("%d",&n);
    printf("Fibonacci series : ");
    for(int i =1 ; i<=n ; i++)
    {
        
        printf("%d\n",first);
        next = first + second;
        first = second;
        second = next;

        
    }

    return 0;
}