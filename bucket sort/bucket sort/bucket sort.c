#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define arr_size 10

/*
��Ŷ ����
  - ���� �����ϰ� ȿ������ ����(������ ������ ���� ������ �䱸������ ����)
  1. ī��Ʈ �迭�� ����
  2. ī��Ʈ �迭�� 0���� �ʱ�ȭ
  3. �Է� �迭�� �ش��ϴ� �ε����� ����
  4. ī��Ʈ �迭�� ����� ������ ��� �迭�� ����
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
	printf("���� �� �ڷ� ��� : ");
	display(arr, arr_size);

	bucket_sort(arr, arr_size, 131);

	printf("���� �� �ڷ� ��� : ");
	display(arr, arr_size);

	return 0;
}