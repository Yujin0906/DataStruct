#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
병합 정렬
*/

void randomize(int* arr, int size, int st, int end)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (end - st + 1) + st;
	}
}

void display(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("");
}

void merge(int* arr, int* arrMerge, int left, int mid, int right)
{
	int i;
	int index1 = left;
	int index2 = mid + 1;
	int indexM = left;
	for (i = left; i <= right; i++)
	{
		arrMerge[i] = arr[i];
	}

	while (index1 <= mid && index2 <= right)
	{
		if (arrMerge[index1] < arrMerge[index2])
			arr[indexM++] = arrMerge[index1++];
		else
			arr[indexM++] = arrMerge[index2++];
	}

	while (index1 <= mid)
		arr[indexM++] = arrMerge[index1++];
	while (index2 <= right)
		arr[indexM++] = arrMerge[index2++];
}

void mergeSortUtil(int* arr, int* arrMerge, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		mergeSortUtil(arr, arrMerge, left, mid);
		mergeSortUtil(arr, arrMerge, mid + 1, right);

		merge(arr, arrMerge, left, mid, right);
	}
}

void mergeSort(int* arr, int size)
{
	int* arrMerge = (int*)malloc(sizeof(int) * size);
	mergeSortUtil(arr, arrMerge, 0, size - 1);
	free(arrMerge);
}

int main()
{
	int size, st, end;
	int* arr;

	printf("배열 크기 입력 : ");
	scanf_s("%d", &size);
	while (getchar() != '\n');

	arr = (int*)malloc(sizeof(int) * size);

	printf("랜덤 시작 수 / 끝 수 입력 : ");
	scanf_s("%d %d", &st, &end);
	while (getchar() != '\n');

	randomize(arr, size, st, end);

	printf("정렬 전 자료 출력 :");
	display(arr, size);

	mergeSort(arr, size);

	printf("정렬 후 자료 출력 : ");
	display(arr, size);

	free(arr);

	return 0;
}