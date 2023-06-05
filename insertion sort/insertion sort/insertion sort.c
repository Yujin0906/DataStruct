#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
���� ����(�ð� ���⵵ : (O(N^2), ���� ���⵵ : O(n))
  - �ڷ� �迭�� ��� ��Ҹ� �տ������� ���ʴ�� �̹� ���ĵ� �迭 �κа� ���Ͽ�,
	�ڽ��� ��ġ�� ã�� �����ϴ� �˰���
  - �����Ϸ��� ������ ���� �ӽ� ������ ����
  - ���� �ݺ����� ���� ��ġ�� ã�� ������ �ӽ� ������ ���� ��
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

	printf("�迭 ũ�� �Է� : ");
	scanf_s("%d", &size);

	arr = (int*)calloc(size, sizeof(int));

	printf("���� ���� �� / �� �� �Է� : ");
	scanf_s("%d %d", &st, &end);

	randomize(arr, size, st, end);

	printf("���� �� �ڷ� ��� :");
	display(arr, size);

	insertion_sort(arr, size);

	printf("���� �� �ڷ� ��� : ");
	display(arr, size);

	free(arr);

	return 0;
}
