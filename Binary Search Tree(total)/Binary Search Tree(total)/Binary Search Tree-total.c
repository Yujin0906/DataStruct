# include <stdio.h>
# include <stdlib.h>

typedef struct tree
{
	int value;
	struct tree* left;
	struct tree* right;
}tree;

tree* addNode(tree* t, int data) // 노드 추가
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

void display(tree* t) // 중위 순회
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
			printf("1. 자식 노드가 없는 경우\n");
			return NULL;
		}
		else if (t->left == NULL)
		{
			temp = t->right;
			free(t);
			printf("자식 노드가 1개인 경우(오른쪽)\n");
			return temp;
		}
		else if (t->right == NULL)
		{
			temp = t->left;
			free(t);
			printf("자식 노드가 1개인 경우(왼쪽)\n");
			return temp;
		}
		else
		{
			printf("자식 노드가 2개인 경우\n");
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

	if (t->value == target) //찾는 값 발견!!!(종료조건)
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
		printf("1. 노드 추가\n");
		printf("2. 노드 제거\n");
		printf("3. 노드 검색\n");
		printf("4. 노드 출력\n");
		printf("5. 최댓값\n");
		printf("6. 최솟값\n");
		printf("0. 프로그램 종료\n");
		printf("메뉴 선택 : [ ]\b\b");
		scanf_s("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 1:
			printf("\n\n삽입 할 정수 입력 : ");
			scanf_s("%d", &data);
			while (getchar() != '\n');
			root = addNode(root, data);
			break;
		case 2:
			printf("\n\n삭제 할 정수 입력 : ");
			scanf_s("%d", &data);
			while (getchar() != '\n');
			root = removeNode(root, data);
			break;
		case 3:
			printf("\n\n검색 할 정수 입력 : ");
			scanf_s("%d", &data);
			while (getchar() != '\n');
			//검색한 정수가 있다면 검색된 노드의 주소를 리턴, 없다면 NULL리턴
			findNode = getFindNode(root, data);
			if (findNode == NULL)
				printf("\n\n\t\t검색한 노드는 존재하지 않습니다.\n");
			else
				printf("\n\n\t\t검색한 노드의 값은 %d입니다.\n", findNode->value);
			break;
		case 4:
			printf("\n\nBST display(오름차순 정렬 | 왼 - 부 - 오) : ");
			display(root);
			break;
		case 5:
			findNode = findMax(root); //최댓값 노드를 구해 리턴
			printf("\n\n\t\t최댓값은 %d입니다.\n", findNode->value);
			break;
		case 6:
			findNode = findMin(root); //최솟값 노드를 구해 리턴
			printf("\n\n\t\t최솟값은 %d입니다.\n", findNode->value);
			break;
		case 0:
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}