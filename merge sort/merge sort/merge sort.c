#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
병합 정렬1
  - 정렬된 2개의 배열 병합 정렬
*/

void merge(int* arr1, int size1, int* arr2, int size2, int* arrMerge)
{
	int index1 = 0;
	int index2 = 0;
	int indexM = 0;
	while (index1 < size1 && index2 < size2)
	{
		if (arr1[index1] < arr2[index2])
		{
			arrMerge[indexM] = arr1[index1];
			indexM++;
			index1++;
		}
		else
		{
			arrMerge[indexM] = arr2[index2];
			indexM++;
			index2++;
		}
	}
	while (index1 < size1)
		arrMerge[indexM++] = arr1[index1++];
	while (index2 < size2)
		arrMerge[indexM++] = arr2[index2++];
}

int main()
{
	int arr1[6] = { 2,4,7,9,11,15 };
	int arr2[6] = { 1,5,8,14,19,21 };
	int arrMerge[12];
	merge(arr1, 6, arr2, 6, arrMerge);
	for (int i = 0; i < 12; i++)
	{
		printf("%d ", arrMerge[i]);
	}
	return 0;
}