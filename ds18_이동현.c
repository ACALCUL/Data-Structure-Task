#include <stdio.h>
#include <stdlib.h>
typedef struct node* nodeptr;
typedef struct node {
	int data;
	nodeptr link;
}node;
void insert(nodeptr alist, int a);

int visited[10000];//visited int 배열 만들기
void dfs(int v, nodeptr* alist);

int main() {
	printf("컴퓨터학부 2022116778 이동현\n");
	printf("Linked adjacency list: \n");
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	int n, i;//n은 vertex 개수
	fscanf_s(in, "%d", &n);
	nodeptr *alist;
	alist = (nodeptr*)malloc(sizeof(nodeptr) * n);

	for (int j = 0; j < n; j++) {
		alist[j] = (nodeptr)malloc(sizeof(node));
		alist[j]->data = j + 1;
		alist[j]->link = NULL;
	}
	for (int j = 0; j < n; j++) {
		for (int k= 0; k < n; k++)
		{
			fscanf_s(in, "%d", &i);
			if (i == 1) {
				insert(alist[j], k + 1);
			}
		}
	}
	fclose(in);

	nodeptr temp;
	for (int j = 0; j < n; j++) {
		printf("Vertex %d: ", j+1);
		temp = alist[j];
		temp = temp->link;
		while (temp) {
			printf("%d ", temp->data);
			temp = temp->link;
		}
		printf("\n");
	}
	//1번 종료, 2번 시작
	printf("scanf 입력: ");
	scanf_s("%d", &i);
	//i는 search할 vertex
	dfs(i, alist);

	return 0;
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

void dfs(int v, nodeptr* alist) {
	nodeptr w;
	visited[v] = 1;
	printf("%d ", v);
	for (w = alist[v - 1]->link; w; w = w->link)
		if (!visited[w->data])
			dfs(w->data, alist);
}