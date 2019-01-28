#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void printArray(int* arr, int length)
{
	for (int* i = arr; i < arr + length; i++)
	{
		printf("%d ", *i);
	}
}

//1
int bubbleSort(int* arr, int length)
{
	int operationsCount = 0;

	for (int i = 0; i < length; i++)
	{
		for (int* j = arr; j < arr + length - 1; j++)
		{
			operationsCount++;
			if (*j > *(j + 1))
			{
				operationsCount++;
				swap(j, j + 1);
			}
		}
	}

	return operationsCount;
}

int betterBubbleSort(int* arr, int length)
{
	int operationsCount = 0;

	for (int i = 0; i < length; i++)
	{
		int flag = 0;

		for (int* j = arr; j < arr + length - 1; j++)
		{
			operationsCount++;
			if (*j > *(j + 1))
			{
				operationsCount++;
				swap(j, j + 1);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			return operationsCount;
		}
	}

	return operationsCount;
}

//2
int shakerSort(int* arr, int length)
{
	int operationsCount = 0;

	int p = 0;
	int q = length - 1;

	while (p < q)
	{
		for (int* j = arr + p; j < arr + q; j++)
		{
			operationsCount++;
			if (*j > *(j + 1))
			{
				operationsCount++;
				swap(j, j + 1);
			}
		}
		q--;

		for (int* j = arr + q; j > arr + p; j--)
		{
			operationsCount++;
			if (*j < *(j - 1))
			{
				operationsCount++;
				swap(j, j - 1);
			}
		}
	}

	return operationsCount;
}

//3
int binarySearch(int* arr, int key, int p, int r)
{
	if (p > r)
	{
		return -2; //invalid p and r parameters
	}

	if (p == r)
	{
		return (*(arr + p) == key) ? p : -1;
	}
	else //if (p < q)
	{
		int q = (p + r) / 2;
		if (*(arr + q) == key)
		{
			return q;
		}
		else if (*(arr + q) > key)
		{
			return binarySearch(arr, key, p, q - 1);
		}
		else
		{
			return binarySearch(arr, key, q + 1, r);
		}
	}
}

//4
//Done in the end of main()

int main()
{
	//1
	int arr[10] = { 5, 9, 4, 2, 8, 3, 1, 6, 0, 7 };
	printf("1) Before Bubble Sort: ");
	printArray(arr, 10);
	printf("\n");
	int bubbleSortOpsCount = bubbleSort(arr, 10);
	printf("After Bubble Sort: ");
	printArray(arr, 10);
	printf("\n");

	int arr2[10] = { 5, 9, 4, 2, 8, 3, 1, 6, 0, 7 };
	printf("Before Better Bubble Sort: ");
	printArray(arr2, 10);
	printf("\n");
	int betterBubbleSortOpsCount = betterBubbleSort(arr2, 10);
	printf("After Better Bubble Sort: ");
	printArray(arr2, 10);
	printf("\n");
	printf("\n");

	//2
	int arr3[10] = { 5, 9, 4, 2, 8, 3, 1, 6, 0, 7 };
	printf("2) Before Shaker Sort: ");
	printArray(arr3, 10);
	printf("\n");
	int shakerSortOpsCount = shakerSort(arr3, 10);
	printf("After Shaker Sort: ");
	printArray(arr3, 10);
	printf("\n");

	//3
	int key = 8;
	printf("\n3) Index of %d element in sorted array is %d\n", key, binarySearch(arr, key, 0, 9));
	printf("\n");

	//4
	printf("4) Operations taken for Bubble Sort: %d\n", bubbleSortOpsCount); // 118 operations
	printf("Operations taken for Better Bubble Sort: %d\n", betterBubbleSortOpsCount); // 109 operations
	printf("Operations taken for Shaker Sort: %d\n", shakerSortOpsCount); // 109 operations

	return 0;
}