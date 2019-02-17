#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define VALUES_RANGE 10

void fillArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % VALUES_RANGE;
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 1. Counting Sort
void countingSort(int* arr, int length)
{
	int frequencyArray[VALUES_RANGE];

	for (int i = 0; i < VALUES_RANGE; i++)
		frequencyArray[i] = 0;

	for (int i = 0; i < length; i++)
		frequencyArray[arr[i]]++;

	int k = 0;
	for (int i = 0; i < VALUES_RANGE; i++)
	{
		for (int j = 0; j < frequencyArray[i]; j++)
		{
			arr[k++] = i;
		}
	}
}

// 2. Quicksort
void quickSort(int* arr, int first, int last)
{
	if (last - first + 1 < 2)
		return;
	else
	{
		int pivot = arr[(first + last) / 2];
		int i = first, j = last;

		do
		{
			while (arr[i] < pivot)
				i++;
			while (arr[j] > pivot)
				j--;

			if (i <= j)
			{
				if (arr[i] > arr[j])
				{
					swap(&arr[i], &arr[j]);
				}
				i++;
				j--;
			}
		} while (i <= j);

		quickSort(arr, first, j);
		quickSort(arr, i, last);
	}
}

// 3. Merge Sort
void merge(int* arr, int p, int q, int r);

void mergeSort(int* arr, int p, int r)
{
	if (r - p + 1 < 2)
		return;
	else
	{
		int q = (p + r) / 2;

		mergeSort(arr, 0, q);
		mergeSort(arr, q + 1, r);

		merge(arr, p, q, r);
	}
}

void merge(int* arr, int p, int q, int r)
{
	int tempLength = r - p + 1;
	int* temp = (int*)malloc((tempLength) * sizeof(int));

	int i = p, j = q + 1;
	for (int k = 0; k < tempLength; k++)
	{
		if (i > q)
		{
			temp[k] = arr[j];
			j++;
		}
		else if (j > r)
		{
			temp[k] = arr[i];
			i++;
		}
		else
		{
			if (arr[i] <= arr[j])
			{
				temp[k] = arr[i];
				i++;
			}
			else if (arr[i] > arr[j])
			{
				temp[k] = arr[j];
				j++;
			}
		}
	}

	for (int i = p, k = 0; i <= r; i++, k++)
		arr[i] = temp[k];

	free(temp);
}

int main()
{
	int arr[SIZE];

	// 1
	printf("Counting Sort:\n");
	fillArray(arr, SIZE);
	printArray(arr, SIZE);
	countingSort(arr, SIZE);
	printArray(arr, SIZE);

	// 2
	printf("\nQuicksort:\n");
	fillArray(arr, SIZE);
	printArray(arr, SIZE);
	quickSort(arr, 0, SIZE - 1);
	printArray(arr, SIZE);

	// 3
	printf("\nMerge Sort:\n");
	fillArray(arr, SIZE);
	printArray(arr, SIZE);
	mergeSort(arr, 0, SIZE - 1);
	printArray(arr, SIZE);

	return 0;
}