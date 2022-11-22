#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 1000000
#define TRUE 1
#define FALSE 0

int queue[MAX_ELEMENTS];
int front, rear;
front = -1;
rear = -1;

int empty(void);
int full(void);
void enqueue(int* queue, int item);
int dequeue(int* queue);

typedef struct node* nodeptr;
typedef struct node {
	int data;
	nodeptr link;
}node;
void insert(nodeptr alist, int a);

int visited[10000];//visited int 배열 만들기
void bfs(int v, nodeptr* alist);


int main() {
	printf("컴퓨터학부 2022116778 이동현\n");
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	int n, i;//n은 vertex 개수
	fscanf_s(in, "%d", &n);
	nodeptr* alist;
	alist = (nodeptr*)malloc(sizeof(nodeptr) * n);

	for (int j = 0; j < n; j++) {
		alist[j] = (nodeptr)malloc(sizeof(node));
		alist[j]->data = j + 1;
		alist[j]->link = NULL;
	}

	int** amatrix;
	amatrix = (int**)malloc(sizeof(int*) * n);
	for (int j = 0; j < n; j++) {
		amatrix[j] = (int*)malloc(sizeof(int)*n);
		amatrix[j][j] = 0;
	}

	for (int j = 0; j < n; j++) {
		for (int k = j+1; k < n; k++)
		{
			fscanf_s(in, "%d", &i);
			if (i == 1) {
				amatrix[j][k]=1;
				amatrix[k][j]=1;
			}
			else {
				amatrix[j][k] = 0;
				amatrix[k][j] = 0;
			}
		}
	}



	fclose(in);

	/*
	printf("\n");
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++)
		{
			printf("%d ", amatrix[j][k]);
		}
		printf("\n");
	}
	*/
	//amatrix 출력 코드

	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++)
		{
			i = amatrix[j][k];
			if (i == 1) {
				insert(alist[j], k + 1);
			}
		}
	}
	/*
	printf("\n");
	nodeptr temp;
	for (int j = 0; j < n; j++) {
		printf("Vertex %d: ", j + 1);
		temp = alist[j];
		temp = temp->link;
		while (temp) {
			printf("%d ", temp->data);
			temp = temp->link;
		}
		printf("\n");
	}
	*/
	//alist 출력 코드
	
	//문제 2 시작
	printf("scanf 입력: ");
	scanf_s("%d", &i);
	while (i != -1) {
		//bfs
		bfs(i, alist);
		printf("scanf 입력: ");
		scanf_s("%d", &i);
	}
}

void insert(nodeptr alist, int a) {
	nodeptr temp, temp2;//temp1은 새로 생성한 노드, temp2는 탐색기
	temp = (nodeptr)malloc(sizeof(node));
	temp2 = alist;
	while (temp2->link) {
		temp2 = temp2->link;
	}
	temp2->link = temp;
	temp->data = a;
	temp->link = NULL;
}



void bfs(int v, nodeptr * alist) {
	nodeptr w;
	visited[v] = TRUE;
	printf("%d ", v);
	enqueue(queue, v);
	while (!empty()) {
		v = dequeue(queue);
		for (w = alist[v - 1]->link;w;w = w->link) {//w->link를 w=w->link로
			if (!visited[w->data]) {
				visited[w->data] = TRUE;
				printf("%d ", w->data);
				enqueue(queue, w->data);
			}
		}
	}
	printf("\n");
	front = -1;
	rear = -1;
	for (int i = 1; i < 1000000; i++) {
		visited[i] = 0;
	}
}


int empty(void) {
	return (front == rear);
}



void enqueue(int* queue, int item) {
	queue[++rear] = item;
}

int dequeue(int* queue) {
	if (empty()) {
		printf("error");
		return 0;
	}
	return queue[++front];
}
