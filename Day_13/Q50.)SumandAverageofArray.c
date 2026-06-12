#include <stdio.h>

int main()
{
	int Size, i, sum = 0;

	printf("Please Enter the Array size = ");
	scanf("%d", &Size);

	int arr[Size];

	int *parr = arr;

	printf("Enter the Array Items = ");
	for (i = 0; i < Size; i++)
	{
		scanf("%d", parr + i);
	}

	for (i = 0; i < Size; i++)
	{
		sum = sum + *(parr + i);
	}

	float avg = (float)sum / Size;

	printf("\nThe Sum of Array Items     = %d\n", sum);
	printf("\nThe Average of Array Items = %.2f\n", avg);
}