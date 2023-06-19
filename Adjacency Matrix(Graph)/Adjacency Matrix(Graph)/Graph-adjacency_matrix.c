#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
	int vertexCount; // ������ ����
	int** arr; // ���� �Ҵ� �� ������ �迭�� �ּ�
}graph;

void graphInit(graph* pGrp, int count)
{
	int i;
	pGrp->vertexCount = count;
	pGrp->arr = (int**)malloc(sizeof(int*) * count);

	for (i = 0; i < count; i++)
	{
		pGrp->arr[i] = (int*)calloc(count, sizeof(int));
	}
}

void addDirectedEdge(graph* pGrp, int start, int end)
{
	pGrp->arr[start][end] = 1;
}

void addUndirectedEdge(graph* pGrp, int start, int end)
{
	addDirectedEdge(pGrp, start, end);
	addDirectedEdge(pGrp, end, start);
}

void display(graph* pGrp)
{
	int i, j;

	printf("���� ����\n");
	for (i = 0; i < pGrp->vertexCount; i++)
	{
		printf("����� %d => ", i);
		for (j = 0; j < pGrp->vertexCount; j++)
		{
			printf("%d ", pGrp->arr[i][j]);
		}
		puts("");
	}
}

void memoryfree(graph* pGrp)
{
	int i;
	for (i = 0; i < pGrp->vertexCount; i++)
	{
		printf("%d�� ���� �޸� ����\n", i);
		free(pGrp->arr[i]);
	}
	free(pGrp->arr);
	printf("������ �迭 ���� �޸� ����");
}

int main()
{
	graph grp;

	graphInit(&grp, 4);

	addUndirectedEdge(&grp, 0, 1);
	addUndirectedEdge(&grp, 0, 2);
	addUndirectedEdge(&grp, 1, 2);
	addUndirectedEdge(&grp, 2, 3);

	display(&grp);

	memoryfree(&grp);

	return 0;
}