// 이진 검색 트리에 노드 삽입하기

#include <stdio.h>

typedef struct tree
{
	int value;
	struct tree* left;
	struct tree* right;
}tree;

tree* addNode(tree* t, int data) {
	if (!t) // t가 NULL이야?
	{
		t = (tree*)malloc(sizeof(tree));
		t->value = data;
		t->left = NULL;
		t->right = NULL;
	}
	else if (data < t->value) // t가 가리키는 value가 data보다 더 크면
		t->left = addNode(t->left, data);
	else if (data > t->value) // t가 가리키는 value가 data보다 더 작으면
		t->right = addNode(t->right, data);

	return t;
}