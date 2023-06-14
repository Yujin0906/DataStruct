#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


/*
힙(Heap)
  -최댓값, 최솟값을 빠르게 검색

Heapify - 배열을 힙으로 변환하는 과정

원소 삽입(MaxHeap 기준)
  1. 배열 끝에 새 원소를 추가
  2. shiftUp

월소 삭제(MaxHeap 기준)
  1. 루트 값을 임시 변수(temp)에 저장
  2. 힙의 마지막 값을 루트로 복사한 후 힙의 크기를 1 감소 시킴
  3. shiftDown
*/

// MaxHeap 기준
typedef struct heap
{
	int* arr; // 배열의 주소 저장
	int size; // 배열에 저장된 개수
	int capacity; // 배열의 최대 용량
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

void heapDisplay(const heap* p) // 힙 출력
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
	int parentIdx = (childIdx - 1) / 2; // 루트인덱스를 구함
	int temp;

	if (parentIdx >= 0 && arr[parentIdx] < arr[childIdx]) // 루트 인덱스가 0이고 자식 인덱스의 값이 더 클 때까지 반봅
	{
		temp = arr[parentIdx]; // 자식 인덱스의 값이 더 크기 때문에 값을 교환
		arr[parentIdx] = arr[childIdx];
		arr[childIdx] = temp; 
		shiftUp(arr, parentIdx); // 위로 올라가며 비교하기 위해 재귀호출을 해줌
	}
}

void heapAdd(heap* p, int value) // 힙 추가
{
	if (p->size >= p->capacity) // 힙 사이즈가 힙의 최대 용량보다 크거나 같으면(overflow)
		return;

	p->arr[p->size] = value; // 배열의 마지막 인덱스에 값을 추가해줌
	p->size++; // p의 힙을 추가 시켜줌(다음 인덱스를 가리키기 위해)

	shiftUp(p->arr, p->size - 1); // shiftUp을 통해 힙화 시켜줌 p->size-1을 한 이유는 
								  // 앞에서 다음 인덱스를 가리키도록 size를 1증가했기 때문
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

int main()
{
	int arr[SIZE] = { 3,7,2,9,1 };

	heap h; // 구조체 변수 선언

	heapify(&h, arr, 5); // 힙, 배열, 배열의 크기)
	heapAdd(&h, 10); // 힙, 추가할 원소값

	printf("Max Heap Display : ");
	heapDisplay(&h); // 힙 출력

	printf("최댓값 : %d\n", heapRemove(&h));
	return 0;
}