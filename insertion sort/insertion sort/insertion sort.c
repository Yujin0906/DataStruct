#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
삽입 정렬(시간 복잡도 : (O(N^2), 공간 복잡도 : O(n))
  - 자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여,
	자신의 위치를 찾아 삽입하는 알고리즘
  - 삽입하려고 선택한 값을 임시 변수에 저장
  - 내부 반복문은 삽입 위치를 찾을 때까지 임시 변수의 값과 비교
*/

void insertion_sort(int* arr, int size)
{
	int i, j, temp;

	for (i = 1; i < size; i++)
	{
		temp = arr[i];
		for (j = i; j > 0 && (arr[j - 1] > temp); j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
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
	{
		arr[i] = rand() % (end - st + 1) + st;
	}
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

	printf("정렬 전 자료 출력 :");
	display(arr, size);

	insertion_sort(arr, size);

	printf("정렬 후 자료 출력 : ");
	display(arr, size);

	free(arr);

	return 0;
}
