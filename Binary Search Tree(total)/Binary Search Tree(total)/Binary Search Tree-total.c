# include <stdio.h>
# include <stdlib.h>

typedef struct tree
{
	int value;
	struct tree* left;
	struct tree* right;
}tree;

tree* addNode(tree* t, int data) // ��� �߰�
{
	if (t == NULL)
	{
		t = (tree*)malloc(sizeof(tree));
		t->value = data;
		t->left = NULL;
		t->right = NULL;
	}
	else if (data < t->value)
		t->left = addNode(t->left, data);
	else if (data > t->value)
		t->right = addNode(t->right, data);

	return t;
}

void display(tree* t) // ���� ��ȸ
{
	if (t != NULL)
	{
		display(t->left);
		printf("%d ", t->value);
		display(t->right);
	}
}

tree* findMax(tree* t)
{
	if (t == NULL)
		return NULL;
	if (t->right == NULL)
		return t;
	else
		return findMax(t->right);
}

tree* findMin(tree* t)
{
	if (t == NULL)
		return NULL;
	if (t->left == NULL)
		return t;
	else
		return findMin(t->left);
}

tree* removeNode(tree* t, int target)
{
	tree* temp = NULL;
	if (t == NULL)
		return NULL;

	if (t->value == target)
	{
		if (t->left == NULL && t->right == NULL)
		{
			free(t);
			printf("1. �ڽ� ��尡 ���� ���\n");
			return NULL;
		}
		else if (t->left == NULL)
		{
			temp = t->right;
			free(t);
			printf("�ڽ� ��尡 1���� ���(������)\n");
			return temp;
		}
		else if (t->right == NULL)
		{
			temp = t->left;
			free(t);
			printf("�ڽ� ��尡 1���� ���(����)\n");
			return temp;
		}
		else
		{
			printf("�ڽ� ��尡 2���� ���\n");
			temp = findMin(t->right);
			t->value = temp->value;
			t->right = removeNode(t->right, temp->value);
		}
	}
	else if (t->value > target)
	{
		t->left = removeNode(t->left, target);
	}
	else
	{
		t->right = removeNode(t->right, target);
	}
}

tree* getFindNode(tree* t, int target)
{
	if (t == NULL)
		return NULL;

	if (t->value == target) //ã�� �� �߰�!!!(��������)
		return t;
	else if (t->value < target)
		return getFindNode(t->right, target);
	else
		return getFindNode(t->left, target);
}

int main()
{
	tree* root = NULL;
	tree* findNode = NULL;
	int choice, data;

	while (1)
	{
		system("cls");
		printf("\n\n\t\t *** Binary Search Tree(BST) ***\n\n");
		printf("1. ��� �߰�\n");
		printf("2. ��� ����\n");
		printf("3. ��� �˻�\n");
		printf("4. ��� ���\n");
		printf("5. �ִ�\n");
		printf("6. �ּڰ�\n");
		printf("0. ���α׷� ����\n");
		printf("�޴� ���� : [ ]\b\b");
		scanf_s("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 1:
			printf("\n\n���� �� ���� �Է� : ");
			scanf_s("%d", &data);
			while (getchar() != '\n');
			root = addNode(root, data);
			break;
		case 2:
			printf("\n\n���� �� ���� �Է� : ");
			scanf_s("%d", &data);
			while (getchar() != '\n');
			root = removeNode(root, data);
			break;
		case 3:
			printf("\n\n�˻� �� ���� �Է� : ");
			scanf_s("%d", &data);
			while (getchar() != '\n');
			//�˻��� ������ �ִٸ� �˻��� ����� �ּҸ� ����, ���ٸ� NULL����
			findNode = getFindNode(root, data);
			if (findNode == NULL)
				printf("\n\n\t\t�˻��� ���� �������� �ʽ��ϴ�.\n");
			else
				printf("\n\n\t\t�˻��� ����� ���� %d�Դϴ�.\n", findNode->value);
			break;
		case 4:
			printf("\n\nBST display(�������� ���� | �� - �� - ��) : ");
			display(root);
			break;
		case 5:
			findNode = findMax(root); //�ִ� ��带 ���� ����
			printf("\n\n\t\t�ִ��� %d�Դϴ�.\n", findNode->value);
			break;
		case 6:
			findNode = findMin(root); //�ּڰ� ��带 ���� ����
			printf("\n\n\t\t�ּڰ��� %d�Դϴ�.\n", findNode->value);
			break;
		case 0:
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}