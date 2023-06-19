#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int* arr; // 메모리 동적 할당
	int top; // 꼭대기
	int capacity; // 배열의 최대 크기
}stack;

void stackInit(stack* p, int size)
{
	p->arr = (int*)malloc(sizeof(int) * size);
	p->top = -1;
	p->capacity = size;
}

int isEmpty(stack* p)
{
	if (p->top < 0)
		return 1;
	else
		return 0;
}

int isFull(stack* p)
{
	if (p->top >= p->capacity - 1)
		return 1;
	else
		return 0;
}

int push(stack* p, int data)
{
	if (isFull(p))
	{
		return -999999999999; // stack overflow
	}
	++(p->top);
	p->arr[p->top] = data;

	return p->arr[p->top];
}

int pop(stack* p)
{
	int delValue;
	if(isEmpty(p))
	{
		return  -999999999999;
	}
	delValue = p->arr[p->top];
	--(p->top);

	return delValue;
}

void stackClear(stack* p)
{
	p->top = -1;
}

void stackDisplay(stack* p)
{
	int i;
	system("cls");
	printf("stack display(LIFO) : ");
	for (i = p->top; i >= 0; i--)
		printf("%d ", p->arr[i]);
	puts("");
}