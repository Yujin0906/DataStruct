// ���� �˻� Ʈ���� ��� �����ϱ�

#include <stdio.h>

typedef struct tree
{
	int value;
	struct tree* left;
	struct tree* right;
}tree;

tree* addNode(tree* t, int data) {
	if (!t) // t�� NULL�̾�?
	{
		t = (tree*)malloc(sizeof(tree));
		t->value = data;
		t->left = NULL;
		t->right = NULL;
	}
	else if (data < t->value) // t�� ����Ű�� value�� data���� �� ũ��
		t->left = addNode(t->left, data);
	else if (data > t->value) // t�� ����Ű�� value�� data���� �� ������
		t->right = addNode(t->right, data);

	return t;
}