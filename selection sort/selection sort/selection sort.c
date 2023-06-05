#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
���� ����(�ð� ���⵵ : (O(N^2), ���� ���⵵ : O(1))
  - �迭���� �ּڰ��� ã�� minIndex�� ������ �� �� �պ��� ��
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

	printf("�迭 ũ�� �Է� : ");
	scanf_s("%d", &size);

	arr = (int*)calloc(size, sizeof(int));

	printf("���� ���� �� / �� �� �Է� : ");
	scanf_s("%d %d", &st, &end);

	randomize(arr, size, st, end);

	printf("���� �� �ڷ� ��� : ");
	display(arr, size);

	selection_sort(arr, size);

	printf("���� �� �ڷ� ��� : ");
	display(arr, size);
	
	free(arr);

	return 0;
}