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
	int leftIdx = (2 * parentIdx) + 1; // 루트의 왼쪽 인덱스
	int rightIdx = leftIdx + 1; // 루트의 오른쪽 인덱스
	int largeIdx = -1;
	int temp;

	if (leftIdx < size) // 왼쪽 인덱스가 size보다 작다면(즉 존재한다면)
		largeIdx = leftIdx; // 라지 인덱스는 왼쪽 인덱스
	if (rightIdx < size && arr[leftIdx] < arr[rightIdx]) // 오른쪽 인덱스가 size보다 작고(즉 존재하며), 오른쪽의 인덱스 값이 왼쪽 인덱스의 값보다 크다면
		largeIdx = rightIdx; // 라지 인덱스는 오른쪽 인덱스

	if (largeIdx != -1 && arr[largeIdx] > arr[parentIdx]) // 라지 인덱스의 값이 존재하고(-1이 아니고) 루트의 자식들이 루트보다 값이 크다면
	{
		temp = arr[largeIdx]; // 루트의 값과 루트의 자식 중 큰 값을 변경 해줌
		arr[largeIdx] = arr[parentIdx];
		arr[parentIdx] = temp;
		shiftDown(arr, largeIdx, size); // 아래로 내려가며 비교하기 위해 재귀호출을 해줌
	}
}

void heapify(heap* p, int* a, int size) // 배열을 힙화 시켜줌
{
	int i;
	p->arr = a;
	p->size = size;
	p->capacity = SIZE;

	for (i = size / 2 - 1; i >= 0; i--) // 자식들이 있는 루트들만 돌기 위해 i 값을 초기화해줌 (이진완전트리이기 때문에 가능함)
	{
		shiftDown(a, i, size);
	}
}

int heapRemove(heap* p) // 힙 삭제
{
	if (p->size <= 0) // 힙 사이즈가 0보다 작으면(underflow)
		return -999999999;

	int maxValue = p->arr[0]; // 최댓값(arr[0])을 변수(maxValue)에 저장해둠
	p->arr[0] = p->arr[p->size - 1]; // arr[0]에 배열의 가장 마지막 인덱스 값을 저장함
	p->size--; // p의 힙을 감소 시켜줌(마지막 인덱스는 이제 사용x)

	shiftDown(p->arr, 0, p->size);

	return maxValue;
}

void heapSort(int* arr, int size)
{
	int* temp;
	int i;
	heap h;

	temp = (int*)malloc(sizeof(int) * size); // 메모리 할당

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

	printf("최대힙을 이용한 힙 정렬(내립차순 정렬) : ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	puts("");

	return 0;
}