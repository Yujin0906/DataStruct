#include <stdio.h>
#include <stdlib.h>

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

void display(graph* p)
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

int main()
{
	graph grp;

	graphInit(&grp, 4);

	addUnDirectedEdge(&grp, 0, 1);
	addUnDirectedEdge(&grp, 0, 2);
	addUnDirectedEdge(&grp, 1, 2);
	addUnDirectedEdge(&grp, 2, 3);

	display(&grp);

	memoryFree(&grp);

	return 0;
}