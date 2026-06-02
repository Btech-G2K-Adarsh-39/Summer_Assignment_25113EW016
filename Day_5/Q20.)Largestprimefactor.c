#include <stdio.h>
int main()
{
    int Number, i = 1, j, Count;
    printf("Please Enter number to Find Factors  :  ");
    scanf("%d", &Number);
    while (i <= Number)
    {
        Count = 0;
        if(Number % i == 0)
        {
            j = 1;
            while(j <= i)
            {
                if(i % j == 0)
                {
                    Count++;
                }
                j++;
            }
            if(Count == 2)
            {
                printf("%d is a Prime Factor \n", i);
            }
        }
        i++;
    }
    return 0;
}