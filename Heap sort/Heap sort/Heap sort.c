#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct heap
{
	int* arr;
	int size;
	int capacity;
}heap;

void shiftDown(int* arr, int parentIdx, int size)
{
	int leftIdx = (2 * parentIdx) + 1; // ��Ʈ�� ���� �ε���
	int rightIdx = leftIdx + 1; // ��Ʈ�� ������ �ε���
	int largeIdx = -1;
	int temp;

	if (leftIdx < size) // ���� �ε����� size���� �۴ٸ�(�� �����Ѵٸ�)
		largeIdx = leftIdx; // ���� �ε����� ���� �ε���
	if (rightIdx < size && arr[leftIdx] < arr[rightIdx]) // ������ �ε����� size���� �۰�(�� �����ϸ�), �������� �ε��� ���� ���� �ε����� ������ ũ�ٸ�
		largeIdx = rightIdx; // ���� �ε����� ������ �ε���

	if (largeIdx != -1 && arr[largeIdx] > arr[parentIdx]) // ���� �ε����� ���� �����ϰ�(-1�� �ƴϰ�) ��Ʈ�� �ڽĵ��� ��Ʈ���� ���� ũ�ٸ�
	{
		temp = arr[largeIdx]; // ��Ʈ�� ���� ��Ʈ�� �ڽ� �� ū ���� ���� ����
		arr[largeIdx] = arr[parentIdx];
		arr[parentIdx] = temp;
		shiftDown(arr, largeIdx, size); // �Ʒ��� �������� ���ϱ� ���� ���ȣ���� ����
	}
}

void heapify(heap* p, int* a, int size) // �迭�� ��ȭ ������
{
	int i;
	p->arr = a;
	p->size = size;
	p->capacity = SIZE;

	for (i = size / 2 - 1; i >= 0; i--) // �ڽĵ��� �ִ� ��Ʈ�鸸 ���� ���� i ���� �ʱ�ȭ���� (��������Ʈ���̱� ������ ������)
	{
		shiftDown(a, i, size);
	}
}

int heapRemove(heap* p) // �� ����
{
	if (p->size <= 0) // �� ����� 0���� ������(underflow)
		return -999999999;

	int maxValue = p->arr[0]; // �ִ�(arr[0])�� ����(maxValue)�� �����ص�
	p->arr[0] = p->arr[p->size - 1]; // arr[0]�� �迭�� ���� ������ �ε��� ���� ������
	p->size--; // p�� ���� ���� ������(������ �ε����� ���� ���x)

	shiftDown(p->arr, 0, p->size);

	return maxValue;
}

void heapSort(int* arr, int size)
{
	int* temp;
	int i;
	heap h;

	temp = (int*)malloc(sizeof(int) * size); // �޸� �Ҵ�

	for (i = 0; i < size; i++)
		temp[i] = arr[i];

	heapify(&h, temp, size);

	for (i = 0; i < size; i++)
		arr[i] = heapRemove(&h);
}

int main()
{
	int arr[SIZE] = { 3,7,2,9,1,6,4,5,10,8 };
	int i;

	heapSort(arr, SIZE);

	printf("�ִ����� �̿��� �� ����(�������� ����) : ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	puts("");

	return 0;
}