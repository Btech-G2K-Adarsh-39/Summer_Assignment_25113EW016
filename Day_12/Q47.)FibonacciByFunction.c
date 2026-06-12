#include <stdio.h>

long findFactorial(int n)
{
long fact = 1;
for (int i = 1; i <= n; i++)
{
fact = fact * i;
}
return fact;
}

int main()
{
int num;
printf("Enter a number: ");
scanf("%d", &num);
if (num < 0)
printf("Invalid input");
else
printf("Factorial of %d is %ld", num, findFactorial(num));
return 0;
}