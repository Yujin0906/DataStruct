#include <stdio.h>
#include <stdlib.h>

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

void display(graph* p)
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