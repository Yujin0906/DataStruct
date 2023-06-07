/*
���� �˻� Ʈ�� ��� ����
  1. �ڽ� ��尡 ���� ���
  2. �ڽ� ��尡 1���� ���
  3. �ڽ� ��尡 2���� ���
*/
#include <stdio.h>

typedef struct tree
{
	int value;
	struct tree* left;
	struct tree* right;
}tree;

tree* findMax(tree* t) // �ڽ� ��尡 2���� ��� root�� ���� �ڽĿ��� ���� ū value���� ���� ��� ã��
{
	if (t)
	{
		while (t->right)
			t = t->right;
	}
	return t;
}
tree* remove(tree* t, int delData)
{
	tree* temp; // �ڽ��� 1���� ���� 2���� ��쿡 �ʿ�
	if (t)
	{
		if (delData == t->value) // �����Ϸ��� delData�� t�� ����Ű�� value ���� ��ġ�ϸ� ���� �����ϱ�
		{
			if ((t->left == NULL) && (t->right == NULL)) // �ڽ� ��尡 ���� ���
			{
				free(t);
				return NULL; // NULL���� ��������
			}
			else
			{
				if (t->left = NULL) // �ڽ� ��尡 1���� ���(������ �ڽĸ� ����)
				{
					temp = t->right; // temp�� ������ �ڽ��� �������ֱ�
					free(t); // t�� ����
					return temp; // temp(t�� ������ �ڽ�)�� ����
				}
				if (t->right = NULL) // �ڽ� ��尡 1���� ���(���� �ڽĸ� ����)
				{
					temp = t->left; // temp�� ���� �ڽ��� �������ֱ�
					free(t); // t�� ����
					return temp; // temp(t�� ���� �ڽ�)�� ����
				}
				// �ڽ� ��尡 2���� ���
				temp = findMax(t->left); // ����0�� ��Ʈ�� ����ٰ� ���������� ���� �ڽĿ��� ���� ū value���� ���� ��带 ã��
				t->value = temp->value; // ���� �ڽĿ��� ���� ū value���� ���� ��带 t�� ������
				t->left = remove(t->left, delData); // ���� �ڽĿ��� ���� ū value���� ���� ��带 ã�Ƽ� �����ϱ�
			}
		}
		else // �����Ϸ��� delData�� t�� ����Ű�� value ���� ��ġ���� �ʴٸ� ��ġ�� ������ ã��
		{
			if (delData < t->value) // �����Ϸ��� delData�� t�� ����Ű�� value ������ �۴ٸ�
				t->left = remove(t->left, delData); // ���� �ڽĿ��� remove ��� �Լ� ȣ���ϱ�
			else // �����Ϸ��� delData�� t�� ����Ű�� value ������ ũ�ٸ�
				t->right = remove(t->right, delData); // ������ �ڽĿ��� remove ��� �Լ� ȣ���ϱ�
		}
	}
	return t;
}