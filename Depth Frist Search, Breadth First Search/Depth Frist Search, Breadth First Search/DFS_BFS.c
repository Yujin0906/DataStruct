#include <stdio.h>
#include <stdlib.h>
#include "stack.h" // DFS
#include "queue.h" // BFS


typedef struct node
{
	int vertex; // 정점
	struct node* next; // 다음 노드 주소
}node;

typedef struct graph
{
	node* head; // 동적 할당된 노드의 주소 저장(출발지 노드)
	int vertexCount; // 정점의 개수
}graph;

void graphInit(graph* p, int count)
{
	int i;
	p->vertexCount = count;
	p->head = (node*)calloc(count, sizeof(node));

	for (i = 0; i < count; i++)
	{
		p->head[i].vertex = i;
		p->head[i].next = NULL;
	}
}

void addDirectedEdge(graph* p, int start, int end) // 방향 그래프(단방향)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->vertex = end;
	newNode->next = NULL;

	if (p->head[start].next == NULL) // 첫 노드라면
	{
		p->head[start].next = newNode;
		return;
	}

	newNode->next = p->head[start].next; // 맨 앞 추가
	p->head[start].next = newNode;
}

void addUnDirectedEdge(graph* p, int start, int end)
{
	addDirectedEdge(p, start, end);
	addDirectedEdge(p, end, start);
}

void graphDisplay(graph* p)
{
	int i;
	node* curNode;

	for (i = 0; i < p->vertexCount; i++)
	{
		curNode = p->head[i].next;
		printf("출발 노드 = %d ", p->head[i].vertex);

		while (curNode != NULL)
		{
			printf("%d ", curNode->vertex);
			curNode = curNode->next;
		}
		puts("");
	}
}

void memoryFree(graph* p)
{
	int i;
	node* delNode;

	for (i = 0; i < p->vertexCount; i++)
	{
		delNode = p->head[i].next; // delNode 변경
		p->head[i].next = delNode->next; // head 변경
		printf("도착지 %d 노드 제거\n", delNode->vertex);
		free(delNode);
	}
}

void DFS_stack(graph* pGrp, int start)
{
	int* visited = (int*)calloc(pGrp->vertexCount, sizeof(int)); // 방문 배열 생성
	int popData;
	stack stk;
	node* curNode;

	stackInit(&stk, pGrp->vertexCount);

	push(&stk, start);
	visited[start] = 1;

	while (stk.top != 0)
	{
		popData = pop(&stk);
		printf("%d ", popData);
		curNode = pGrp->head[popData].next;

		while (curNode != NULL)
		{
			if (visited[curNode->vertex] == 0)
			{
				push(&stk, curNode->vertex); // push
				visited[curNode->vertex] = 1; // 방문 체크
			}
			curNode = curNode->next; // 방문 노드의 다음 노드로 이동
		}
	}
	puts("");

	free(stk.arr); // 스택 동적 메모리 제거
	free(visited); // 방문 배열 제거
}

void BFS_queue(graph* pGrp, int start)
{
	node* curNode;
	int dequeData;
	int* visited = (int*)calloc(pGrp->vertexCount, sizeof(int)); // 방문 배열 생성

	circularQueue que;
	queueInit(&que, pGrp->vertexCount);

	enqueue(&que, pGrp->head[start].vertex);
	visited[start] = 1; // 방문 체크

	printf("BFS Traversal with queue : ");
	while (que.count != 0)
	{
		dequeData = dequeue(&que);
		printf("%d ", dequeData);

		curNode = pGrp->head[dequeData].next;

		while (curNode != NULL)
		{
			if (visited[curNode->vertex] == 0)
			{
				enqueue(&que, curNode->vertex);
				visited[curNode->vertex] = 1; // 방문 체크
			}
			curNode = curNode->next;
		}
	}
	puts("\n");
	free(que.arr);
	free(visited);
}

void DFS(graph* pGrp, int start, int* visited)
{
	node* curNode = pGrp->head[start].next;
	visited[start] = 1;

	while (curNode != NULL)
	{
		if (visited[curNode->vertex] == 0)
		{
			printf("%d ", curNode->vertex);
			DFS(pGrp, curNode->vertex, visited); // 재귀 호출
		}
		curNode = curNode->next;
	}
}

void DFS_reculsive(graph* pGrp, int start)
{
	int* visited = (int*)calloc(pGrp->vertexCount, sizeof(int));

	printf("DFS Traversal with reculsive call : ");
	printf("%d ", pGrp->head[start].vertex);

	DFS(pGrp, start, visited);
	puts("\n");
}

int main()
{
	graph grp; //구조체 변수 선언

	graphInit(&grp, 9);

	addUnDirectedEdge(&grp, 0, 1);
	addUnDirectedEdge(&grp, 1, 3);
	addUnDirectedEdge(&grp, 1, 2);
	addUnDirectedEdge(&grp, 2, 3);
	addUnDirectedEdge(&grp, 2, 4);
	addUnDirectedEdge(&grp, 3, 4);
	addUnDirectedEdge(&grp, 3, 5);
	addUnDirectedEdge(&grp, 5, 6);
	addUnDirectedEdge(&grp, 5, 7);
	addUnDirectedEdge(&grp, 6, 8);

	graphDisplay(&grp);

	//출발 정점을 0번에서 시작!!!
	DFS_stack(&grp, 0); //깊이 우선 탐색(스택을 이용)
	DFS_reculsive(&grp, 0); //깊이 우선 탐색(재귀호출을 이용)
	BFS_queue(&grp, 0); //너비 우선 탐색(큐를 이용)

	memoryFree(&grp);
	return 0;
}