/*
이진 검색 트리 노드 삭제
  1. 자식 노드가 없는 경우
  2. 자식 노드가 1개인 경우
  3. 자식 노드가 2개인 경우
*/
#include <stdio.h>

typedef struct tree
{
	int value;
	struct tree* left;
	struct tree* right;
}tree;

tree* findMax(tree* t) // 자식 노드가 2개인 경우 root의 왼쪽 자식에서 가장 큰 value값을 가진 노드 찾기
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
	tree* temp; // 자식이 1개인 경우와 2개인 경우에 필요
	if (t)
	{
		if (delData == t->value) // 삭제하려는 delData와 t가 가리키는 value 값이 일치하면 이제 삭제하기
		{
			if ((t->left == NULL) && (t->right == NULL)) // 자식 노드가 없는 경우
			{
				free(t);
				return NULL; // NULL값을 리턴해줌
			}
			else
			{
				if (t->left = NULL) // 자식 노드가 1개인 경우(오른쪽 자식만 존재)
				{
					temp = t->right; // temp에 오른쪽 자식을 저장해주기
					free(t); // t를 삭제
					return temp; // temp(t의 오른쪽 자식)를 리턴
				}
				if (t->right = NULL) // 자식 노드가 1개인 경우(왼쪽 자식만 존재)
				{
					temp = t->left; // temp에 왼쪽 자식을 저장해주기
					free(t); // t를 삭제
					return temp; // temp(t의 왼쪽 자식)를 리턴
				}
				// 자식 노드가 2개인 경우
				temp = findMax(t->left); // 레벨0인 루트를 지운다고 가정했을때 왼쪽 자식에서 가장 큰 value값을 가진 노드를 찾기
				t->value = temp->value; // 왼쪽 자식에서 가장 큰 value값을 가진 노드를 t로 덮어씌우기
				t->left = remove(t->left, delData); // 왼쪽 자식에서 가장 큰 value값을 가진 노드를 찾아서 삭제하기
			}
		}
		else // 삭제하려는 delData와 t가 가리키는 value 값이 일치하지 않다면 일치할 때까지 찾기
		{
			if (delData < t->value) // 삭제하려는 delData가 t가 가리키는 value 값보다 작다면
				t->left = remove(t->left, delData); // 왼쪽 자식에서 remove 재귀 함수 호출하기
			else // 삭제하려는 delData가 t가 가리키는 value 값보다 크다면
				t->right = remove(t->right, delData); // 오른쪽 자식에서 remove 재귀 함수 호출하기
		}
	}
	return t;
}