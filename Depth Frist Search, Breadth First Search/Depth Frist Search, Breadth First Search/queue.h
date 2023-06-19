#pragma once

#include <stdlib.h>

typedef struct circularQueue
{
	int* arr; // ���� �޸� �ּҸ� ����
	int rear; // �����Ϸ��� �ε���
	int front; // �����Ϸ��� �ε���
	int count; // �迭�� ����� ����
	int capacity; // �迭�� �ִ� �뷮
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