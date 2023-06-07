/*
트리의 순회 방식을 보고 원본 트리 구현하기 ==> 전위-중위 또는 중위-후위의 순회 방식을 알아야 함
  - 단일 순회 방식으로는 트리를 복원할 수 없음
  - 중위 순회 방식이 없으면 트리를 복원할 수 없음
*/

// 전위 순회와 중위 순회를 보고 트리 복원

#include <stdio.h>

typedef struct tree // 트리 구조체 선언
{
	int value;
	struct tree* left;
	struct tree* right;
}tree;

int get_inorder_index(int* inorder, int begin, int end, int target) // 중위 순위에서 target(root)값 찾아서 index 값 리턴해주기
{
	for (int i = begin; i <= end; i++) // inorder 배열을 돌면서 root값 찾기
	{
		if (inorder[i] == target) // 일치하면
			return i;			  // inorder의 index 값 리턴해주기
	}
	return -1;
}

tree* tree_restore(int* preorder, int* inorder, int begin, int end) // 새로운 트리 생성하기(?)
{
	static int preIdx = 0; // static 값으로 preIdx를 0으로 초기화
	tree* newNode = NULL; // newNode는 NULL 값으로 초기화
	if (begin <= end) // 만약 begin이 end보다 작거나 같으면
	{
		newNode = (tree*)malloc(sizeof(tree)); // newNode를 생성
		newNode->value = preorder[preIdx++]; // newNode의 value 값에 전위 순회의 인덱스 값을 부여해주고 전위 순회으 인덱스 값은 증가 시켜줌
		newNode->left = newNode->right = NULL; // newNode의 왼쪽과 오른쪽에서 NULL 값으로 초기화
		int inIdx = get_inorder_index(inorder, begin, end, newNode->value); // 중위 순회가 지금 가리키는 인덱스를 선언해주고 get_inorder_index를 통해 inIdx의 인덱스 값을 리턴받음
		newNode->left = tree_restore(preorder, inorder, begin, inIdx - 1); // newNode의 왼쪽에는 begin부터 inIdx-1 값을 재귀호출,
		newNode->right = tree_restore(preorder, inorder, inIdx + 1, end); // newNode의 오른쪽에는 inIdx+1부터 end 값으로 재귀호출하며 초기화 해줌
	}
	return newNode; // newNode를 리턴하면서 이어줌
}

int main()
{
	tree* root = NULL;
	int preorder[6] = { 1,2,3,4,5,6 };
	int inorder[6] = { 4,2,5,1,6,3 };
	root = tree_restore(preorder, inorder, 0, 5);
	return 0;
}