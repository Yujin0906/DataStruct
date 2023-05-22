#include <stdio.h>
#include <stdlib.h> // malloc()사용


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

}void insert_node_rear() { // 노드 맨 뒤 삽입
	node* newNode; // newNode 생성
	newNode = (node*)malloc(sizeof(node)); // newNode의 동적할당(초기화?)
	scanf_s("%d", &newNode->value); // newNode의 노드 값 부여
	newNode->next = NULL; // newNode의 다음 노드의 주소를 가르키는 값에 NULL값 주기
	node* curNode; // curNode 생성
	if (head == NULL) // head가 NULL이라면 즉, 아직 아무 노드도 가르키고 있지 않다는 뜻
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

// 중간에 삽입하기, 특정 노드 삭제 구현하기

