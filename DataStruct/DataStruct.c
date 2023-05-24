#include <stdio.h>
#include <stdlib.h> // malloc()사용

/*
// 연결리스트
typedef struct node
{
	int value; // 노드의 값
	struct node* next; // 다음 노드의 주소를 가르키는 값
}node;

node* head = NULL; // head 생성, 초기화

void insert_node_front() { // 노드 맨 앞에 삽입
	node* newNode; // newNode 생성
	newNode = (node*)malloc(sizeof(node)); // newNode의 동적할당(초기화?) 
	scanf_s("%d", &newNode->value); // newNode의 노드 값 부여
	newNode->next = NULL; // newNode의 다음 노드의 주소를 가르키는 값에 NULL값 주기

	if (head == NULL) // head가 NULL이라면 즉, 아직 아무 노드도 가르키고 있지 않다는 뜻
	{
		head = newNode; // head에 newNode의 주솟값을 부여
		return; // 리턴해줌
	}
	newNode->next = head; // head가 NULL이 아니라면 즉, 이미 노드를 가르키고 있다면 newNode(새로 생긴 노드)의 next 값에 head(즉, 내가 이제 가리켜야 할 노드의 주소)를 부여
	head = newNode; // head에 newNode(새로 생긴 노드)의 주솟값을 부여해야 함

}
void display() { // 순회하면서 출력
	if (head == NULL) { // 연결리스트가 구성되어 있는지 확인
		printf("연결리스트가 구성되지 않아 출력x"); // 구성되어 있지 않을때 출력
		return; // 함수 종료
	}
	node* curNode; // curNode(현재 가리키는 노드의 주솟값을 알려줌) 생성
	curNode = head; // 현재 가리키는 노드의 주솟값은 head
	while (curNode != NULL) // 현재 가리키는 노드의 주솟값이 null이 아닐 때까지만 반복
	{
		printf("%d", curNode->value); // 현재 가리키는 노드의 value 값을 출력
		curNode = curNode->next; // 다음으로 가리키는 주솟값으로 이동
	}
	printf("%d", curNode->value); // 마지막은 NULL값이 포함되어 있어 출력되지 못했기때문에 마지막 value값 출력
}
void insert_node_rear() { // 노드 맨 뒤 삽입
	node* newNode; // newNode 생성
	newNode = (node*)malloc(sizeof(node)); // newNode의 동적할당(초기화?)
	scanf_s("%d", &newNode->value); // newNode의 노드 값 부여
	newNode->next = NULL; // newNode의 다음 노드의 주소를 가르키는 값에 NULL값 주기
	node* curNode; // curNode 생성
	if (head == NULL) // head가 NULL이라면 즉, 아직 아무 노드도 가리키고 있지 않다는 뜻
	{
		head = newNode; // head에 newNode의 주솟값을 부여
		return; // 리턴해줌
	}
	curNode = head; // 맨 뒤에 삽입 해야함으로 순회를 반복해야함, 현재 가리키는 노드의 주솟값은 head
	while (curNode->next != NULL) { // 현재 가리키는 노드의 주솟값이 null이 아닐 때까지만 반복
		curNode = curNode->next; // 다음으로 가리키는 주솟값으로 이동
	}
	curNode->next = newNode; // 현재 가리키는 노드의 주솟값을 새로 생성된 newNode에 부여함으로써 노드 맨 뒤 삽입
}
void remove_all_node() // 전체 노드 삭제
{
	node* delNode; // delNode 생성
	delNode = head; // delNode에 head의 값 부여
	while (head != NULL) // head가 가리키는 노드의 주솟값이 null이 아닐 때까지만 반복
	{
		head = head->next; // head는 head의 다음 주솟값 즉, 다음 가리키는 노드
		free(delNode); // head와 delNode가 일치하지 않고, free로 delNode가 가리키는 노드를 삭제함
		delNode = head; // delNode는 head의 주솟값을 공유(?)
	}
}
void remove_node() // 특정 노드 삭제
{
	int num; // 삭제할 노드 번호 생성
	node* delNode, * curNode = NULL; // 삭제할 노드, 현재 방문한 노드
	if (head == NULL) // head가 NULL이라면 즉,  아직 아무 노드도 가리키고 있지 않다는 뜻
	{
		return; // 함수를 리턴함
	}
	scanf_s("%d", &num); // 삭제할 노드의 value값 입력
	if (head->value == num) // head값(맨 처음 값)과 삭제할 노드의 value값이 같다면
	{
		delNode = head; // 삭제할 노드에 head값을 부여
		head = head->next; // head는 다음 주소를 가리키는 값으로 이동
		free(delNode); // head가 가리키고 있지 않기 때문에 삭제
		return; // 끝났으면 함수 리턴
	}
	curNode = head; // 처음과 같지 않다면 현재 방문한 노드에 head값을 주고 순회해야함
	while (curNode->next != NULL) // 현재 방문한 노드가 가리키는 다음값이 널이 아닐때까지 반복
	{
		delNode = curNode->next; // 삭제할 노드는 현재 방문한 노드가 가리키는 다음 값
		if (delNode->value == num) // 만약 삭제할 노드의 value 값이 삭제하고 싶은 value값과 같다면
		{
			curNode->next = delNode->next; // 현재 방문한 노드의 다음 값에 삭제할 노드의 다음 값을 부여함
			free(delNode); // 삭제할 노드를 삭제함
		}
		if (curNode->next != NULL) // 만약 방문한 노드의 다음값이 널이 아니라면
		{
			curNode = curNode->next; // 방문한 노드는 현재 방문한 노드의 다음 값을 부여받음
		}
	}
}
void insert_node_sort() // 정렬 삽입
{
	node* newNode = (node*)malloc(sizeof(node)); // 삽입할 노드 생성
	scanf_s("%d", &newNode->value); // 노드의 값 입력
	newNode->next = NULL; // 노드의 다음 가리키는 값은 NULL
	// 1. head == NULL
	if (head == NULL) // head가 NULL이라면 즉,  아직 아무 노드도 가리키고 있지 않다는 뜻
	{
		head = newNode; // head에 newNode값을 부여
		return; // 함수를 리턴함
	}
	// 2. 가장 작은 값 삽입
	if (head->value > newNode->value) // head의 값이 새로운 노드의 값보다 크면
	{
		newNode->next = head; // 새로운 노드의 다음 값은 head를 가리킴
		head = newNode; // head는 newNode를 가리킴
		return; // 함수를 리턴함
	}
	// 3. 중간에 값을 삽입
	node* curNode, * prevNode; // 중간에 값을 삽입하기 위해 현재 방문중인 노드와 이전 방문 노드 값을 생성
	curNode = prevNode = head; // 현재 방문한 노드와 이전 방문 노드는 head와 같음(처음 시작)
	while (curNode->next != NULL) // 현재 방문한 노드의 다음 가리키는 주솟값이 NULL이 아닐때까지 반복
	{
		curNode = curNode->next; // 현재 방문한 노드는 현재 방문한 노드의 다음 값을 가리킴(가장 작은 값을 삽입할때 체크했기때문)
		if (curNode->value > newNode->value) // 만약 현재 방문한 노드의 값이 새로운 노드의 값보다 크면
		{
			newNode->next = curNode; // 새로운 노드의 다음 주솟값은 현재 방문 노드를 가리킴
			prevNode->next = newNode; // 이전 방문 노드의 다음 주솟값은 새로운 노드를 가리킴
			return; // 함수를 리턴함
		}
		prevNode = prevNode->next; // 이전 방문 노드는 이전 방문 노드의 다음 주솟값을 가리킴
	}
	// 4. 가장 큰 값 삽임
	curNode->next = newNode; // 가장 큰 값은 앞에서 이미 비교를 다 했기때문에 현재 방문한 노드의 다음 주솟값은 newNode를 가리키면 됨
}

// 이중연결리스트(아직x)

// 스택(배열)
typedef struct stack // 스택 배열 선언
{
	int arr; // 배열 arr
	int top; // 제일 높은 꼭대기
	int capacity; // 배열의 최대 크기
}stack;

void arrstackInit(stack* p, int size) // 배열 스택 초기화
{
	p->top = 0; // 맨 꼭대기 = 0
	p->capacity = size; // 배열의 최대 크기
	p->arr = (int*)malloc(sizeof(int) * size); // 배열의 최대 크기 동적 할당
}
void arrstakcPush(stack* p, int data) // 스택 푸쉬
{
	p->arr[p->top] = data; // 배열의 가장 꼭대기에 데이터 추가
	(p->top)++; // 데이터를 추가한 후 다음 꼭대기로 이동
}
void arrstackPop(stack* p) // 스택 팝
{
	(p->top)--; // 실제로 제거를 할 수 없으므로 꼭대기를 감소시킴(전에 가리키던 top은 쓰레기값을 가지고 있음)
}
void arrDisplay(stack* p) // 스택 출력
{
	for (int i = p->top - 1; i >= 0; i--) // LIFO이기 때문에 뒤에서 부터 출력, -1을 하는 이유는 top이 가리키는 곳부터 하면 쓰레기값도 함께 출력됨
	{
		printf("%d", p->arr[i]); // arr스택 배열 출력
	}
}
void arrstackClear(stack* p) // 스택 초기화
{
	p->top = 0; // 꼭대기 값을 0으로 만들어줌
}

// 스택(연결리스트)
typedef struct node // 스택 연결리스트 선언
{
	int value; // 노드의 값 생성
	struct node* next; // 노드가 가리키는 주솟값 생성
}node;

void liststackPush(node** head, int data)  // 스택 푸쉬
{
	node* newNode = NULL; // 새로운 노드 생성 후 널값 부여
	newNode = (node*)malloc(sizeof(node)); // 새로운 노드의 크기를 동적 할당 받음
	newNode->value = data; // 새로운 노드의 값에 data 추가
	newNode->next = NULL; // 새로운 노드의 가리키는 주솟값에 NULL값 부여

	if (*head == NULL)  
	{
		*head = newNode;
	}
	newNode->next = *head;
	*head = newNode;
}
void liststackPop(node** head) // 스택 팝
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
void liststackDisplay(node* head) // 스택 출력
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
void liststackClear(node** head) // 스택 초기화
{
	node* delNode = *head;
	while (*head)
	{
		*head = (*head)->next;
		free(delNode);
		delNode = (*head);
	}
}

// 큐(배열)
typedef struct queue
{
	int* arr; // 동적 메모리의 주소를 저장하는 포인터
	int front; // 삭제 위치(배열의 첨자)
	int rear; // 삽입 위치(배열의 첨자)
	int count; // 저장된 원소의 개수
	int capacity; // 배열의 최대 용량
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
	return delValue; // 삭제된 값 리턴
}

void arrdisplayqueue(queue* pQue) {
	int i;
	system("cls");
	printf("queue display : ");
	if (pQue->count <= 0)
	{
		printf("queue가 비어있는 상태입니다.");
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

// 큐(연결리스트)
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

// 재귀함수
void reculsive(int n)
{
	if (n == 0)
		return;
	printf("%d\n", n);
	printf("%d\n", n);
	reculsive(n - 1);
}

// 구구단 재귀함수
void multitable(int num)
{
	if (num == 0)
	{
		printf("함수종료\n");
		return;
	}
	multitable(num - 1);
	printf("2 * %d = %d\n", num, 2 * num);
}

// 거듭제곱
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

// 팩토리얼
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

// 유클리드 호제법
int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

// 이진 검색
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

// 하노이 탑
void hanoi(int n, char from, char temp, char to)
{
	if (n == 1)
	{
		printf("%c -> %c로 이동", from, to);
		return;
	}
	hanoi(n - 1, from, to, temp);
	printf("%c -> %c로 이동", from, to);
	hanoi(n - 1, temp, from, to);
}

// 피보나치 수열
double fibo(int n)
{
	if (n == 1 || n == 2) // 종료 조건
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}

// 피보나치 수열(동적 계획법, top-down)
double mz[100] = { 0,1,1 }; // 메모이제이션 배열을 0으로 초기화
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

// 피보나치 수열(동적 계획법, bottom-up)
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
	reculsive(3); // 재귀함수

	multitable(9); // 구구단 재귀함수

	int base, exponent; // 거듭제곱
	printf("밑수 입력 : ");
	scanf_s("%d", &base);

	printf("지수 입력 : ");
	scanf_s("%d", &exponent);

	printf("%d^%d = %0.2f\n", base, exponent, power(base, exponent));

	int num; // 팩토리얼
	double result;

	printf("자연수 입력 : ");
	scanf_s("%d", &num);

	printf("%d! = ", num);
	result = factorial(num);
	printf("%f\n", result);

	int n1, n2, result; // 유클리드 호제법
	printf("최대 공약수를 구할 정수 2개 입력 : ");
	scanf_s("%d %d", &n1, &n2);

	result = gcd(n1, n2);

	printf("%d와 %d의 최대 공약수는 %d입니다.\n", n1, n2, result);

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 }; // 이진 검색
	int index;

	index = binarySearch(arr, 0, 9, 9);

	if (index == -1)
		printf("찾는 값은 존재하지 않습니다.\n");
	else
		printf("찾는 값은 arr[%d]번째 있습니다.\n", index);

	hanoi(3, 'A', 'B', 'C'); // 하노이 탑

	int num; // 피보나치 수열
	double result;

	printf("피보나치 수열의 몇 번째 항을 구하시겠습니까?");
	scanf_s("%d", &num);

	result = fibo(num);

	printf("%d항의 값은 %0.f입니다.\n", num, result);

	int num; // 피보나치 수열(동적 계획법, top-down)
	printf("피보나치 수열의 몇 번째 항을 구하시겠습니까?");
	scanf_s("%d", &num);

	printf("%d항의 값은 %0.f입니다.\n", num, fibo2(num));*/

	int num; // 피보나치 수열(동적 계획법, bottom-up)
	printf("피보나치 수열의 몇 번째 항을 구하시겠습니까?");
	scanf_s("%d", &num);

	printf("%d항의 값은 %0.f입니다.\n", num, fibo3(num));

	return 0;
}