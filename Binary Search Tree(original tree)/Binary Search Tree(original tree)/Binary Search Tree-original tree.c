/*
Ʈ���� ��ȸ ����� ���� ���� Ʈ�� �����ϱ� ==> ����-���� �Ǵ� ����-������ ��ȸ ����� �˾ƾ� ��
  - ���� ��ȸ ������δ� Ʈ���� ������ �� ����
  - ���� ��ȸ ����� ������ Ʈ���� ������ �� ����
*/

// ���� ��ȸ�� ���� ��ȸ�� ���� Ʈ�� ����

#include <stdio.h>

typedef struct tree // Ʈ�� ����ü ����
{
	int value;
	struct tree* left;
	struct tree* right;
}tree;

int get_inorder_index(int* inorder, int begin, int end, int target) // ���� �������� target(root)�� ã�Ƽ� index �� �������ֱ�
{
	for (int i = begin; i <= end; i++) // inorder �迭�� ���鼭 root�� ã��
	{
		if (inorder[i] == target) // ��ġ�ϸ�
			return i;			  // inorder�� index �� �������ֱ�
	}
	return -1;
}

tree* tree_restore(int* preorder, int* inorder, int begin, int end) // ���ο� Ʈ�� �����ϱ�(?)
{
	static int preIdx = 0; // static ������ preIdx�� 0���� �ʱ�ȭ
	tree* newNode = NULL; // newNode�� NULL ������ �ʱ�ȭ
	if (begin <= end) // ���� begin�� end���� �۰ų� ������
	{
		newNode = (tree*)malloc(sizeof(tree)); // newNode�� ����
		newNode->value = preorder[preIdx++]; // newNode�� value ���� ���� ��ȸ�� �ε��� ���� �ο����ְ� ���� ��ȸ�� �ε��� ���� ���� ������
		newNode->left = newNode->right = NULL; // newNode�� ���ʰ� �����ʿ��� NULL ������ �ʱ�ȭ
		int inIdx = get_inorder_index(inorder, begin, end, newNode->value); // ���� ��ȸ�� ���� ����Ű�� �ε����� �������ְ� get_inorder_index�� ���� inIdx�� �ε��� ���� ���Ϲ���
		newNode->left = tree_restore(preorder, inorder, begin, inIdx - 1); // newNode�� ���ʿ��� begin���� inIdx-1 ���� ���ȣ��,
		newNode->right = tree_restore(preorder, inorder, inIdx + 1, end); // newNode�� �����ʿ��� inIdx+1���� end ������ ���ȣ���ϸ� �ʱ�ȭ ����
	}
	return newNode; // newNode�� �����ϸ鼭 �̾���
}

int main()
{
	tree* root = NULL;
	int preorder[6] = { 1,2,3,4,5,6 };
	int inorder[6] = { 4,2,5,1,6,3 };
	root = tree_restore(preorder, inorder, 0, 5);
	return 0;
}