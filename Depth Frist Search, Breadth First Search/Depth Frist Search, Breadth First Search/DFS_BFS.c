#include <stdio.h>
#include <stdlib.h>
#include "stack.h" // DFS
#include "queue.h" // BFS


typedef struct node
{
	int vertex; // ����
	struct node* next; // ���� ��� �ּ�
}node;

typedef struct graph
{
	node* head; // ���� �Ҵ�� ����� �ּ� ����(����� ���)
	int vertexCount; // ������ ����
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

void addDirectedEdge(graph* p, int start, int end) // ���� �׷���(�ܹ���)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->vertex = end;
	newNode->next = NULL;

	if (p->head[start].next == NULL) // ù �����
	{
		p->head[start].next = newNode;
		return;
	}

	newNode->next = p->head[start].next; // �� �� �߰�
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
		printf("��� ��� = %d ", p->head[i].vertex);

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
		delNode = p->head[i].next; // delNode ����
		p->head[i].next = delNode->next; // head ����
		printf("������ %d ��� ����\n", delNode->vertex);
		free(delNode);
	}
}

void DFS_stack(graph* pGrp, int start)
{
	int* visited = (int*)calloc(pGrp->vertexCount, sizeof(int)); // �湮 �迭 ����
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
				visited[curNode->vertex] = 1; // �湮 üũ
			}
			curNode = curNode->next; // �湮 ����� ���� ���� �̵�
		}
	}
	puts("");

	free(stk.arr); // ���� ���� �޸� ����
	free(visited); // �湮 �迭 ����
}

void BFS_queue(graph* pGrp, int start)
{
	node* curNode;
	int dequeData;
	int* visited = (int*)calloc(pGrp->vertexCount, sizeof(int)); // �湮 �迭 ����

	circularQueue que;
	queueInit(&que, pGrp->vertexCount);

	enqueue(&que, pGrp->head[start].vertex);
	visited[start] = 1; // �湮 üũ

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
				visited[curNode->vertex] = 1; // �湮 üũ
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
			DFS(pGrp, curNode->vertex, visited); // ��� ȣ��
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
	graph grp; //����ü ���� ����

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

	//��� ������ 0������ ����!!!
	DFS_stack(&grp, 0); //���� �켱 Ž��(������ �̿�)
	DFS_reculsive(&grp, 0); //���� �켱 Ž��(���ȣ���� �̿�)
	BFS_queue(&grp, 0); //�ʺ� �켱 Ž��(ť�� �̿�)

	memoryFree(&grp);
	return 0;
}