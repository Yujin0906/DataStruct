#pragma once

#include <stdlib.h>

typedef struct circularQueue
{
	int* arr; // 동적 메모리 주소를 저장
	int rear; // 삽입하려는 인덱스
	int front; // 삭제하려는 인덱스
	int count; // 배열에 저장된 개수
	int capacity; // 배열의 최대 용량
}circularQueue;

void queueInit(circularQueue* p, int size)
{
	p->arr = (int*)malloc(sizeof(int) * size);
	p->rear = 0;
	p->front = 0;
	p->count = 0;
	p->capacity = size;
}

void enqueue(circularQueue* p, int data)
{
	if (p->count == p->capacity)
	{
		return;
	}
	p->arr[p->rear] = data;
	p->rear++;
	p->count++;

	if (p->rear == p->capacity)
		p->rear = 0;
}

int dequeue(circularQueue* p)
{
	int delValue;
	if (p->count == 0)
	{
		return -999999999999;
	}

	delValue = p->arr[p->front];
	p->front++;
	p->count--;

	if (p->front == p->capacity)
		p->front = 0;

	return delValue;
}