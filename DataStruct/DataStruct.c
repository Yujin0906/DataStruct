#include <stdio.h>
#include <stdlib.h> // malloc()���


// ���Ḯ��Ʈ
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
}
void insert_node_rear() { // ��� �� �� ����
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
void remove_node() // Ư�� ��� ����
{
	int num; // ������ ��� ��ȣ ����
	node* delNode, * curNode = NULL; // ������ ���, ���� �湮�� ���
	if (head == NULL) // head�� NULL�̶�� ��,  ���� �ƹ� ��嵵 ����Ű�� ���� �ʴٴ� ��
	{
		return; // �Լ��� ������
	}
	scanf_s("%d", &num); // ������ ����� value�� �Է�
	if (head->value == num) // head��(�� ó�� ��)�� ������ ����� value���� ���ٸ�
	{
		delNode = head; // ������ ��忡 head���� �ο�
		head = head->next; // head�� ���� �ּҸ� ����Ű�� ������ �̵�
		free(delNode); // head�� ����Ű�� ���� �ʱ� ������ ����
		return; // �������� �Լ� ����
	}
	curNode = head; // ó���� ���� �ʴٸ� ���� �湮�� ��忡 head���� �ְ� ��ȸ�ؾ���
	while (curNode->next != NULL) // ���� �湮�� ��尡 ����Ű�� �������� ���� �ƴҶ����� �ݺ�
	{
		delNode = curNode->next; // ������ ���� ���� �湮�� ��尡 ����Ű�� ���� ��
		if (delNode->value == num) // ���� ������ ����� value ���� �����ϰ� ���� value���� ���ٸ�
		{
			curNode->next = delNode->next; // ���� �湮�� ����� ���� ���� ������ ����� ���� ���� �ο���
			free(delNode); // ������ ��带 ������
		}
		if (curNode->next != NULL) // ���� �湮�� ����� �������� ���� �ƴ϶��
		{
			curNode = curNode->next; // �湮�� ���� ���� �湮�� ����� ���� ���� �ο�����
		}
	}
}
void insert_node_sort() // ���� ����
{
	node* newNode = (node*)malloc(sizeof(node)); // ������ ��� ����
	scanf_s("%d", &newNode->value); // ����� �� �Է�
	newNode->next = NULL; // ����� ���� ����Ű�� ���� NULL
	// 1. head == NULL
	if (head == NULL) // head�� NULL�̶�� ��,  ���� �ƹ� ��嵵 ����Ű�� ���� �ʴٴ� ��
	{
		head = newNode; // head�� newNode���� �ο�
		return; // �Լ��� ������
	}
	// 2. ���� ���� �� ����
	if (head->value > newNode->value) // head�� ���� ���ο� ����� ������ ũ��
	{
		newNode->next = head; // ���ο� ����� ���� ���� head�� ����Ŵ
		head = newNode; // head�� newNode�� ����Ŵ
		return; // �Լ��� ������
	}
	// 3. �߰��� ���� ����
	node* curNode, * prevNode; // �߰��� ���� �����ϱ� ���� ���� �湮���� ���� ���� �湮 ��� ���� ����
	curNode = prevNode = head; // ���� �湮�� ���� ���� �湮 ���� head�� ����(ó�� ����)
	while (curNode->next != NULL) // ���� �湮�� ����� ���� ����Ű�� �ּڰ��� NULL�� �ƴҶ����� �ݺ�
	{
		curNode = curNode->next; // ���� �湮�� ���� ���� �湮�� ����� ���� ���� ����Ŵ(���� ���� ���� �����Ҷ� üũ�߱⶧��)
		if (curNode->value > newNode->value) // ���� ���� �湮�� ����� ���� ���ο� ����� ������ ũ��
		{
			newNode->next = curNode; // ���ο� ����� ���� �ּڰ��� ���� �湮 ��带 ����Ŵ
			prevNode->next = newNode; // ���� �湮 ����� ���� �ּڰ��� ���ο� ��带 ����Ŵ
			return; // �Լ��� ������
		}
		prevNode = prevNode->next; // ���� �湮 ���� ���� �湮 ����� ���� �ּڰ��� ����Ŵ
	}
	// 4. ���� ū �� ����
	curNode->next = newNode; // ���� ū ���� �տ��� �̹� �񱳸� �� �߱⶧���� ���� �湮�� ����� ���� �ּڰ��� newNode�� ����Ű�� ��
}

// ���߿��Ḯ��Ʈ(����x)

// ����(�迭, ���Ḯ��Ʈ)
typedef struct stack // ���� �迭 ����
{
	int arr; // �迭 arr
	int top; // ���� ���� �����
	int capacity; // �迭�� �ִ� ũ��
}stack;

void arrstackInit(stack* p, int size) // �迭 ���� �ʱ�ȭ
{
	p->top = 0; // �� ����� = 0
	p->capacity = size; // �迭�� �ִ� ũ��
	p->arr = (int*)malloc(sizeof(int) * size); // �迭�� �ִ� ũ�� ���� �Ҵ�
}
void arrstakcPush(stack* p, int data) // ���� Ǫ��
{
	p->arr[p->top] = data; // �迭�� ���� ����⿡ ������ �߰�
	(p->top)++; // �����͸� �߰��� �� ���� ������ �̵�
}
void arrstackPop(stack* p) // ���� ��
{
	(p->top)--; // ������ ���Ÿ� �� �� �����Ƿ� ����⸦ ���ҽ�Ŵ(���� ����Ű�� top�� �����Ⱚ�� ������ ����)
}
void arrDisplay(stack* p) // ���� ���
{
	for (int i = p->top - 1; i >= 0; i--) // LIFO�̱� ������ �ڿ��� ���� ���, -1�� �ϴ� ������ top�� ����Ű�� ������ �ϸ� �����Ⱚ�� �Բ� ��µ�
	{
		printf("%d", p->arr[i]); // arr���� �迭 ���
	}
}
void arrstackClear(stack* p) // ���� �ʱ�ȭ
{
	p->top = 0; // ����� ���� 0���� �������
}

typedef struct node // ���� ���Ḯ��Ʈ ����
{
	int value; // ����� �� ����
	struct node* next; // ��尡 ����Ű�� �ּڰ� ����
}node;

void liststackPush(node** head, int data)  // ���� Ǫ��
{
	node* newNode = NULL; // ���ο� ��� ���� �� �ΰ� �ο�
	newNode = (node*)malloc(sizeof(node)); // ���ο� ����� ũ�⸦ ���� �Ҵ� ����
	newNode->value = data; // ���ο� ����� ���� data �߰�
	newNode->next = NULL; // ���ο� ����� ����Ű�� �ּڰ��� NULL�� �ο�

	if (*head == NULL)  
	{
		*head = newNode;
	}
	newNode->next = *head;
	*head = newNode;
}
void liststackPop(node** head) // ���� ��
{
	node* delNode = NULL;
	if (*head == NULL)
	{
		return;
	}
	delNode = *head;
	*head = (*head)->next;
	free(delNode);
}
void liststackDisplay(node* head) // ���� ���
{
	node* curNode = head;
	if (head == NULL)
	{
		return;
	}
	while (curNode->next)
	{
		curNode = curNode->next;
	}
}
void liststackClear(node** head) // ���� �ʱ�ȭ
{
	node* delNode = *head;
	while (*head)
	{
		*head = (*head)->next;
		free(delNode);
		delNode = (*head);
	}
}