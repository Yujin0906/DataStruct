// ���� �˻� Ʈ�� �ִ�, �ּڰ� ã��
// �ִ��� �ݺ���, �ּڰ��� ���ȣ���� ����Ͽ� ����

typedef struct tree
{
	int value;
	struct tree* left;
	struct tree* right; 
}tree;

tree* findMax(tree* t) // �ݺ����� ���
{
	if (t) // t�� ������?
	{
		while (t->right) // t�� right���� ���� ������ �ݺ�
			t = t->right; // t�� t�� right ���� ����
	}
	return t; // t�� ���� ��������
}

tree* findMin(tree* t) // ���ȣ���� ���
{
	if (t->left) // t�� left ���� ������?
	{
		t = findMin(t->left); // t�� t�� left���� ������ findMin�� ȣ��
	}
	return t; // t�� ���� ���ȣ���ϸ� ��������
}