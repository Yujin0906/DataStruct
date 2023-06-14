#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


/*
��(Heap)
  -�ִ�, �ּڰ��� ������ �˻�

Heapify - �迭�� ������ ��ȯ�ϴ� ����

���� ����(MaxHeap ����)
  1. �迭 ���� �� ���Ҹ� �߰�
  2. shiftUp

���� ����(MaxHeap ����)
  1. ��Ʈ ���� �ӽ� ����(temp)�� ����
  2. ���� ������ ���� ��Ʈ�� ������ �� ���� ũ�⸦ 1 ���� ��Ŵ
  3. shiftDown
*/

// MaxHeap ����
typedef struct heap
{
	int* arr; // �迭�� �ּ� ����
	int size; // �迭�� ����� ����
	int capacity; // �迭�� �ִ� �뷮
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

void heapDisplay(const heap* p) // �� ���
{
	int i;
	for (i = 0; i < p->size; i++)
	{
		printf("%d ", p->arr[i]);
	}
	puts("");
}

void shiftUp(int* arr, int childIdx)
{
	int parentIdx = (childIdx - 1) / 2; // ��Ʈ�ε����� ����
	int temp;

	if (parentIdx >= 0 && arr[parentIdx] < arr[childIdx]) // ��Ʈ �ε����� 0�̰� �ڽ� �ε����� ���� �� Ŭ ������ �ݺ�
	{
		temp = arr[parentIdx]; // �ڽ� �ε����� ���� �� ũ�� ������ ���� ��ȯ
		arr[parentIdx] = arr[childIdx];
		arr[childIdx] = temp; 
		shiftUp(arr, parentIdx); // ���� �ö󰡸� ���ϱ� ���� ���ȣ���� ����
	}
}

void heapAdd(heap* p, int value) // �� �߰�
{
	if (p->size >= p->capacity) // �� ����� ���� �ִ� �뷮���� ũ�ų� ������(overflow)
		return;

	p->arr[p->size] = value; // �迭�� ������ �ε����� ���� �߰�����
	p->size++; // p�� ���� �߰� ������(���� �ε����� ����Ű�� ����)

	shiftUp(p->arr, p->size - 1); // shiftUp�� ���� ��ȭ ������ p->size-1�� �� ������ 
								  // �տ��� ���� �ε����� ����Ű���� size�� 1�����߱� ����
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

int main()
{
	int arr[SIZE] = { 3,7,2,9,1 };

	heap h; // ����ü ���� ����

	heapify(&h, arr, 5); // ��, �迭, �迭�� ũ��)
	heapAdd(&h, 10); // ��, �߰��� ���Ұ�

	printf("Max Heap Display : ");
	heapDisplay(&h); // �� ���

	printf("�ִ� : %d\n", heapRemove(&h));
	return 0;
}