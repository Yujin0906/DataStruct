#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
퀵 정렬(시간 복잡도 : (O(N^2), 공간 복잡도 : O(1))
  - 그룹을 나누는 기준을 피벗(마음대로 선택할 수 있음)이라하며 가장 빠른 정렬 알고리즘 중 하나
*/

void randomize(int* arr, int size, int st, int end)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < size; i++)
		arr[i] = rand() % (end - st + 1) + st;
}

void display(int* parr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", parr[i]);
	puts("");
}

void quick(int* arr, int left, int right)
{
	int PL = left;
	int PR = right;
	int pivot = arr[(left + right) / 2];
	int temp;

	do {
		while (arr[PL] < pivot)
			PL++;
		while (arr[PR] > pivot)
			PR--;
		if (PL <= PR)
		{
			temp = arr[PL];
			arr[PL] = arr[PR];
			arr[PR] = temp;
			PL++;
			PR--;
		}
	} while (PL <= PR);

	if (left < PR)
		quick(arr, left, PR);
	if (PL < right)
		quick(arr, PL, right);
}

void quick_sort(int* arr, int size)
{
	quick(arr, 0, size - 1);
}

int main()
{
	int size, st, end;
	int* arr;

	printf("배열 크기 입력 : ");
	scanf_s("%d", &size);

	arr = (int*)calloc(size, sizeof(int));

	printf("랜덤 시작 수 / 끝 수 입력 : ");
	scanf_s("%d %d", &st, &end);

	randomize(arr, size, st, end);

	printf("정렬 전 자료 출력 : ");
	display(arr, size);

	quick_sort(arr, size);

	printf("정렬 후 자료 출력 : ");
	display(arr, size);

	free(arr);

	return 0;
}