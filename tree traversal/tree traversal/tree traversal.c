#include <stdio.h>
#include <stdlib.h>

/*
트리 순회
*/

typedef struct tree
{
	int value;
	struct tree* left;
	struct tree* right;
}tree;

tree* setBinTree(int* arr, int size, int index)
{
	int leftIdx, rightIdx;
	tree* newNode;

	newNode = (tree*)malloc(sizeof(tree));
	newNode->value = arr[index];
	newNode->left = NULL;
	newNode->right = NULL;

	leftIdx = 2 * index + 1;
	rightIdx = leftIdx + 1;

	if (leftIdx < size)
		newNode->left = setBinTree(arr, size, leftIdx);

	if (rightIdx < size)
		newNode->right = setBinTree(arr, size, rightIdx);

	return newNode;
}

void displayPreOrder(tree* t) // 전위 순회
{
	if (t != NULL)
	{
		printf("%d ", t->value);
		displayPreOrder(t->left);
		displayPreOrder(t->right);
	}
}

void displayInOrder(tree* t) // 중위 순회
{
	if (t != NULL)
	{
		displayInOrder(t->left);
		printf("%d ", t->value);
		displayInOrder(t->right);
	}
}

void displayPostOrder(tree* t) // 후위 순회
{
	if (t != NULL)
	{
		displayPostOrder(t->left);
		displayPostOrder(t->right);
		printf("%d ", t->value);
	}
}

tree* memoryFree(tree* t) // 후위 순회로 데이터 제거
{
	if (t != NULL)
	{
		memoryFree(t->left);
		memoryFree(t->right);
		printf("%d노드 제거\n", t->value);
		free(t);
	}
	return NULL;
}

int main()
{
	int arr[] = { 6,4,8,2,5,7,9,1,3 };

	tree* root = NULL;
	root = setBinTree(arr, 9, 0);

	printf("tree preorder : ");
	displayPreOrder(root);
	puts("");

	printf("tree inorder : ");
	displayInOrder(root);
	puts("");

	printf("tree postorder : ");
	displayPostOrder(root);
	puts("");

	root = memoryFree(root);

	return 0;
}