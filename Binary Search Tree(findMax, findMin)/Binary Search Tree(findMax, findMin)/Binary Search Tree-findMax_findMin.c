// 이진 검색 트리 최댓값, 최솟값 찾기
// 최댓값은 반복문, 최솟값은 재귀호출을 사용하여 구현

typedef struct tree
{
	int value;
	struct tree* left;
	struct tree* right; 
}tree;

tree* findMax(tree* t) // 반복문을 사용
{
	if (t) // t가 존재해?
	{
		while (t->right) // t의 right값이 있을 때까지 반복
			t = t->right; // t에 t의 right 값을 대입
	}
	return t; // t의 값을 리턴해줌
}

tree* findMin(tree* t) // 재귀호출을 사용
{
	if (t->left) // t의 left 값이 존재해?
	{
		t = findMin(t->left); // t는 t의 left값을 가지고 findMin을 호출
	}
	return t; // t의 값을 재귀호출하며 리턴해줌
}