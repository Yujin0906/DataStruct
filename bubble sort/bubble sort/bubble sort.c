#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
버블 정렬(시간 복잡도 : O(N^2), 공간 복잡도(O(1))
  - 서로 인접한 두 요소를 비교하여 정렬하는 알고리즘
*/

void bubble_sort(int* arr, int size)
{
	int i, j, temp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
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

void randomize(int* arr, int size, int st, int end)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < size; i++)
		arr[i] = rand() % (end - st + 1) + st;
}

int main(void)
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

	bubble_sort(arr, size);

	printf("정렬 후 자료 출력 : ");
	display(arr, size);

	free(arr);

	return 0;
}
