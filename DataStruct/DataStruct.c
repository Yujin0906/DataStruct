#include <stdio.h>
#include <stdlib.h> // malloc()���

/*
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

// ����(�迭)
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

// ����(���Ḯ��Ʈ)
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

// ť(�迭)
typedef struct queue
{
	int* arr; // ���� �޸��� �ּҸ� �����ϴ� ������
	int front; // ���� ��ġ(�迭�� ÷��)
	int rear; // ���� ��ġ(�迭�� ÷��)
	int count; // ����� ������ ����
	int capacity; // �迭�� �ִ� �뷮
}queue;

void arrqueueInit(queue* pQue, int size) {
	pQue->arr = (int*)malloc(sizeof(int) * size);
	pQue->front = pQue->rear = pQue->count = 0;
	pQue->capacity = size;
}

void arrenqueue(queue* pQue, int data) {
	if (pQue->count >= pQue->capacity)
	{
		printf("queue overflow\n");
		return;
	}
	pQue->arr[pQue->rear] = data;
	pQue->rear++;
	pQue->count++;
	if (pQue->rear == pQue->capacity)
	{
		pQue->rear = 0;
	}
}

int arrdequeue(queue* pQue) {
	int delValue;
	if (pQue->count <= 0) // underflow
	{
		return -999999999;
	}
	delValue = pQue->arr[pQue->front];
	pQue->front++;
	pQue->count--;
	if (pQue->front == pQue->capacity)
	{
		pQue->front = 0;
	}
	return delValue; // ������ �� ����
}

void arrdisplayqueue(queue* pQue) {
	int i;
	system("cls");
	printf("queue display : ");
	if (pQue->count <= 0)
	{
		printf("queue�� ����ִ� �����Դϴ�.");
		return;
	}
	for (i = pQue->front; i < (pQue->front + pQue->count); i++)
	{
		printf("%d ", pQue->arr[i % pQue->capacity]);
	}
	puts("");
}

void arrclearqueue(queue* pQue) {
	pQue->front = pQue->rear = pQue->count = 0;
}

// ť(���Ḯ��Ʈ)
void listenqueue(node** pHead, node** pTail, int data)
{
	node* newNode;
	newNode = (node*)malloc(sizeof(node));
	newNode->value = data;
	newNode->next = NULL;

	if (*pHead == NULL)
	{
		*pHead = newNode;
		*pTail = newNode;
		return;
	}
	(*pTail)->next = newNode;
	(*pTail) = newNode;
}

void listdequeue(node** pHead, node** pTail) {
	int delValue;
	node* delNode;
	if (*pHead == NULL)
	{
		return -999999999;
	}
	delNode = *pHead;
	delValue = delNode->value;
	*pHead = (*pHead)->next;
	free(delNode);
	if (*pHead == NULL)
	{
		*pTail = NULL;
	}
	return delValue;
}

void listdisplayqueue(node* head, node* tail)
{
	node* curNode;
	if (head == NULL)
	{
		return;
	}
	curNode = head;
	while (curNode != NULL)
	{
		printf("%d", curNode->value);
		curNode = curNode->next;
	}
	printf("%d", curNode->value);
}

void listclearqueue(node** pHead, node** pTail)
{
	node* delNode;
	if (*pHead == NULL)
	{
		return;
	}
	while (*pHead != NULL)
	{
		delNode = *pHead;
		(*pHead) = (*pHead)->next;
		free(delNode);
	}
	(*pTail) = NULL;	
}
*/

// ����Լ�
void reculsive(int n)
{
	if (n == 0)
		return;
	printf("%d\n", n);
	printf("%d\n", n);
	reculsive(n - 1);
}

// ������ ����Լ�
void multitable(int num)
{
	if (num == 0)
	{
		printf("�Լ�����\n");
		return;
	}
	multitable(num - 1);
	printf("2 * %d = %d\n", num, 2 * num);
}

// �ŵ�����
double power(int x, int y)
{
	if (y == 0)
		return 1;
	else
	{
		if (y % 2 == 0)
			return power(x * x, y / 2);
		else
			return x * power(x * x, y / 2);
	}
}

// ���丮��
double factorial(int n)
{
	if (n <= 1)
	{
		printf("%d = ", n);
		return 1;
	}
	printf("%d * ", n);
	return n * factorial(n - 1);
}

// ��Ŭ���� ȣ����
int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

// ���� �˻�
int binarySearch(int* arr, int left, int right, int target)
{
	int mid = (left + right) / 2;

	if (left > right)
		return 1;
	if (arr[mid] == target)
		return mid;
	if (arr[mid] < target)
		return binarySearch(arr, mid + 1, right, target);
	else
		return binarySearch(arr, left, mid - 1, target);
}

// �ϳ��� ž
void hanoi(int n, char from, char temp, char to)
{
	if (n == 1)
	{
		printf("%c -> %c�� �̵�", from, to);
		return;
	}
	hanoi(n - 1, from, to, temp);
	printf("%c -> %c�� �̵�", from, to);
	hanoi(n - 1, temp, from, to);
}

// �Ǻ���ġ ����
double fibo(int n)
{
	if (n == 1 || n == 2) // ���� ����
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}

// �Ǻ���ġ ����(���� ��ȹ��, top-down)
double mz[100] = { 0,1,1 }; // �޸������̼� �迭�� 0���� �ʱ�ȭ
double fibo2(int n)
{
	if (mz[n] != 0)
	{
		return mz[n];
	}
	else
	{
		mz[n] = fibo2(n - 1) + fibo2(n - 2);
		return mz[n];
	}
}

// �Ǻ���ġ ����(���� ��ȹ��, bottom-up)
double mz[100] = { 0,1,1 };
double fibo3(int n)
{
	int i;
	for (i = 3; i <= n; i++)
		mz[i] = mz[i - 1] + mz[i - 2];
	return mz[n];
}

int main()
{/*
	reculsive(3); // ����Լ�

	multitable(9); // ������ ����Լ�

	int base, exponent; // �ŵ�����
	printf("�ؼ� �Է� : ");
	scanf_s("%d", &base);

	printf("���� �Է� : ");
	scanf_s("%d", &exponent);

	printf("%d^%d = %0.2f\n", base, exponent, power(base, exponent));

	int num; // ���丮��
	double result;

	printf("�ڿ��� �Է� : ");
	scanf_s("%d", &num);

	printf("%d! = ", num);
	result = factorial(num);
	printf("%f\n", result);

	int n1, n2, result; // ��Ŭ���� ȣ����
	printf("�ִ� ������� ���� ���� 2�� �Է� : ");
	scanf_s("%d %d", &n1, &n2);

	result = gcd(n1, n2);

	printf("%d�� %d�� �ִ� ������� %d�Դϴ�.\n", n1, n2, result);

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 }; // ���� �˻�
	int index;

	index = binarySearch(arr, 0, 9, 9);

	if (index == -1)
		printf("ã�� ���� �������� �ʽ��ϴ�.\n");
	else
		printf("ã�� ���� arr[%d]��° �ֽ��ϴ�.\n", index);

	hanoi(3, 'A', 'B', 'C'); // �ϳ��� ž

	int num; // �Ǻ���ġ ����
	double result;

	printf("�Ǻ���ġ ������ �� ��° ���� ���Ͻðڽ��ϱ�?");
	scanf_s("%d", &num);

	result = fibo(num);

	printf("%d���� ���� %0.f�Դϴ�.\n", num, result);

	int num; // �Ǻ���ġ ����(���� ��ȹ��, top-down)
	printf("�Ǻ���ġ ������ �� ��° ���� ���Ͻðڽ��ϱ�?");
	scanf_s("%d", &num);

	printf("%d���� ���� %0.f�Դϴ�.\n", num, fibo2(num));*/

	int num; // �Ǻ���ġ ����(���� ��ȹ��, bottom-up)
	printf("�Ǻ���ġ ������ �� ��° ���� ���Ͻðڽ��ϱ�?");
	scanf_s("%d", &num);

	printf("%d���� ���� %0.f�Դϴ�.\n", num, fibo3(num));

	return 0;
}