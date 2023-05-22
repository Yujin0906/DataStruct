#include <stdio.h>
#include <stdlib.h> // malloc()���


typedef struct node
{
	int value; // ����� ��
	struct node* next; // ���� ����� �ּҸ� ����Ű�� ��
}node;

node* head = NULL; // head ����, �ʱ�ȭ

void insert_node_front() { // ��� �� �տ� ����
	node* newNode; // newNode ����
	newNode = (node*)malloc(sizeof(node)); // newNode�� �����Ҵ�(�ʱ�ȭ?) 
	scanf_s("%d", &newNode->value); // newNode�� ��� �� �ο�
	newNode->next = NULL; // newNode�� ���� ����� �ּҸ� ����Ű�� ���� NULL�� �ֱ�

	if (head == NULL) // head�� NULL�̶�� ��, ���� �ƹ� ��嵵 ����Ű�� ���� �ʴٴ� ��
	{
		head = newNode; // head�� newNode�� �ּڰ��� �ο�
		return; // ��������
	}
	newNode->next = head; // head�� NULL�� �ƴ϶�� ��, �̹� ��带 ����Ű�� �ִٸ� newNode(���� ���� ���)�� next ���� head(��, ���� ���� �����Ѿ� �� ����� �ּ�)�� �ο�
	head = newNode; // head�� newNode(���� ���� ���)�� �ּڰ��� �ο��ؾ� ��

}

void display() { // ��ȸ�ϸ鼭 ���
	if (head == NULL) { // ���Ḯ��Ʈ�� �����Ǿ� �ִ��� Ȯ��
		printf("���Ḯ��Ʈ�� �������� �ʾ� ���x"); // �����Ǿ� ���� ������ ���
		return; // �Լ� ����
	}
	node* curNode; // curNode(���� ����Ű�� ����� �ּڰ��� �˷���) ����
	curNode = head; // ���� ����Ű�� ����� �ּڰ��� head
	while (curNode != NULL) // ���� ����Ű�� ����� �ּڰ��� null�� �ƴ� �������� �ݺ�
	{
		printf("%d", curNode->value); // ���� ����Ű�� ����� value ���� ���
		curNode = curNode->next; // �������� ����Ű�� �ּڰ����� �̵�
	}
	printf("%d", curNode->value); // �������� NULL���� ���ԵǾ� �־� ��µ��� ���߱⶧���� ������ value�� ���

}void insert_node_rear() { // ��� �� �� ����
	node* newNode; // newNode ����
	newNode = (node*)malloc(sizeof(node)); // newNode�� �����Ҵ�(�ʱ�ȭ?)
	scanf_s("%d", &newNode->value); // newNode�� ��� �� �ο�
	newNode->next = NULL; // newNode�� ���� ����� �ּҸ� ����Ű�� ���� NULL�� �ֱ�
	node* curNode; // curNode ����
	if (head == NULL) // head�� NULL�̶�� ��, ���� �ƹ� ��嵵 ����Ű�� ���� �ʴٴ� ��
	{
		head = newNode; // head�� newNode�� �ּڰ��� �ο�
		return; // ��������
	}
	curNode = head; // �� �ڿ� ���� �ؾ������� ��ȸ�� �ݺ��ؾ���, ���� ����Ű�� ����� �ּڰ��� head
	while (curNode->next != NULL) { // ���� ����Ű�� ����� �ּڰ��� null�� �ƴ� �������� �ݺ�
		curNode = curNode->next; // �������� ����Ű�� �ּڰ����� �̵�
	}
	curNode->next = newNode; // ���� ����Ű�� ����� �ּڰ��� ���� ������ newNode�� �ο������ν� ��� �� �� ����
}

void remove_all_node() // ��ü ��� ����
{
	node* delNode; // delNode ����
	delNode = head; // delNode�� head�� �� �ο�
	while (head != NULL) // head�� ����Ű�� ����� �ּڰ��� null�� �ƴ� �������� �ݺ�
	{
		head = head->next; // head�� head�� ���� �ּڰ� ��, ���� ����Ű�� ���
		free(delNode); // head�� delNode�� ��ġ���� �ʰ�, free�� delNode�� ����Ű�� ��带 ������
		delNode = head; // delNode�� head�� �ּڰ��� ����(?)
	}
}

// �߰��� �����ϱ�, Ư�� ��� ���� �����ϱ�

