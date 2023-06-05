#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
선택 정렬(시간 복잡도 : (O(N^2), 공간 복잡도 : O(1))
  - 배열에서 최솟갑을 찾아 minIndex에 저장한 후 맨 앞부터 둠
*/
void selection_sort(int* arr, int size)
{
	int i, j, minIndex, temp;
	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (arr[minIndex] > arr[j])
				minIndex = j;
		}
		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
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

	selection_sort(arr, size);

	printf("정렬 후 자료 출력 : ");
	display(arr, size);
	
	free(arr);

	return 0;
}