#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
	int vertexCount; // 정점의 개수
	int** arr; // 동적 할당 된 포인터 배열의 주소
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

	printf("간선 연결\n");
	for (i = 0; i < pGrp->vertexCount; i++)
	{
		printf("출발지 %d => ", i);
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
		printf("%d행 동적 메모리 해제\n", i);
		free(pGrp->arr[i]);
	}
	free(pGrp->arr);
	printf("포인터 배열 동적 메모리 해제");
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