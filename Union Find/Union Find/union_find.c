#include <stdio.h>

int get_parent(int* parent, int index)
{
	if (parent[index] == index)
		return index;
	return get_parent(parent, parent[index]);
}

void unoin_parent(int* parent, int x, int y)
{
	x = get_parent(parent, x);
	y = get_parent(parent, y);

	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}

int find_parent(int* parent, int x, int y)
{
	x = get_parent(parent, x);
	y = get_parent(parent, y);

	if (x == y)
		return 1;
	else
		return 0;
}

int main()
{
	int parent[10];
	
	for (int i = 0; i < 10; i++)
		parent[i] = i;

	unoin_parent(parent, 0, 1);
	unoin_parent(parent, 1, 2);
	unoin_parent(parent, 2, 3);
	unoin_parent(parent, 4, 5);
	unoin_parent(parent, 5, 6);
	unoin_parent(parent, 6, 7);

	if (find_parent(parent, 3, 4) == 1)
		printf("3°ú 4´Â ¿¬°á ¾ÈµÊ\n");
	else
		printf("3°ú 4´Â ¿¬°áµÊ\n");

	unoin_parent(parent, 3, 4);

	if(find_parent(parent,3,4)==1)
		printf("3°ú 4´Â ¿¬°áµÊ\n");
	else
		printf("3°ú 4´Â ¿¬°á ¾ÈµÊ\n");

	return 0;
}