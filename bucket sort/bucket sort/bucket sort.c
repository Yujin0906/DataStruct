#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define arr_size 10

/*
버킷 정렬
  - 가장 간단하고 효율적인 형태(데이터 범위에 대한 엄격한 요구사항이 있음)
  1. 카운트 배열을 만듦
  2. 카운트 배열을 0으로 초기화
  3. 입력 배열에 해당하는 인덱스를 증가
  4. 카운트 배열에 저장된 정보를 결과 배열에 저장
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

void bucket_sort(int* arr, int size, int range)
{
	int i, j, index;
	int* bucket = (int*)calloc(range, sizeof(int));

	for (i = 0; i < size; i++)
	{
		bucket[arr[i]]++;
	}

	index = 0;
	for (i = 1; i < range; i++)
	{
		for (j = 1; j <= bucket[i]; j++)
			arr[index++] = i;
	}
	free(bucket);
}

int main()
{
	int arr[arr_size];
	randomize(arr, arr_size, 1, 130);
	printf("정렬 전 자료 출력 : ");
	display(arr, arr_size);

	bucket_sort(arr, arr_size, 131);

	printf("정렬 후 자료 출력 : ");
	display(arr, arr_size);

	return 0;
}