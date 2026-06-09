#include<stdio.h>
int add(int,int);
int main()
{
   int a,b;
   printf("\nEnter The Two Values:");
   scanf("%d%d",&a,&b);
   printf("\nAddition:%d",add(a,b));
   return 0;
}
int add(int a,int b)
{
   int c;
   c=a+b;
   return c;
}      