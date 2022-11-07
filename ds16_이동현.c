#include <stdio.h>
#include <stdlib.h>
typedef struct tree* treepointer;
typedef struct tree {
	int key;
	treepointer leftchild, rightchild;
}tree;

int* search(treepointer tree, int k);
treepointer modifiedsearch(treepointer tree, int k);
void insert(treepointer* node, int k);

treepointer queue[100000];
int front = -1, rear = -1;

treepointer maketree(int k);
void addq(treepointer item);
treepointer deleteq(void);
void levelorder(treepointer ptr);

int main() {
	printf("학부: 컴퓨터학부 학번: 2022116778 이름: 이동현\n");
	int i;
	treepointer node;
	node= (treepointer)malloc(sizeof(tree));
	node = NULL;

	FILE* in;
	fopen_s(&in, "in.txt", "r");
	while (fscanf_s(in, "%d", &i) != EOF) {
		insert(&node, i);
	}
	levelorder(node);
	printf("\n");
	//level order 출력 문제 없음
	printf("Scanf: ");
	scanf_s("%d", &i);
	if (i == -1) return 0;
	if (search(node, i))
		printf("S\n");
	else
		printf("E\n");
	while(i!=-1){
		printf("Scanf: ");
		scanf_s("%d", &i);
		if (i == -1) return 0;
		if (search(node, i))
			printf("S\n");
		else
			printf("E\n");
	} 
	
	return 0;
}

int* search(treepointer tree, int k) {
	while (tree) {
		if (k == tree->key) return &(tree->key);
		if (k < tree->key) 
			tree = tree->leftchild;
		else 
			tree = tree->rightchild;
	}
	return NULL;
}

treepointer modifiedsearch(treepointer tree, int k) {
	treepointer tree_1;
	tree_1= (treepointer)malloc(sizeof(tree));
	tree_1 = tree;
	while (tree) {
		tree_1 = tree;
		if (k == tree->key) return NULL;
		if (k < tree->key)
			tree = tree->leftchild;
		else
			tree = tree->rightchild;
	}
	return tree_1;
}

void insert(treepointer* node, int k) {
	treepointer ptr, temp = modifiedsearch(*node, k);
	if (temp || !(*node)) {
		ptr = (treepointer)malloc(sizeof(*ptr));
		ptr->key = k;
		ptr->leftchild = NULL;
		ptr->rightchild = NULL;
		if (*node) {
			if (k < temp->key) temp->leftchild = ptr;
			else temp->rightchild = ptr;
		}
		else *node = ptr;
	}
}

void addq(treepointer item) {
	queue[++rear] = item;
}

treepointer deleteq(void) {
	return queue[++front];
}

void levelorder(treepointer ptr) {
	if (!ptr) return;//NULL return
	addq(ptr);
	for (;;) {
		ptr = deleteq();
		if (ptr) {
			printf("%d ", ptr->key);
			if (ptr->leftchild)
				addq(ptr->leftchild);
			if (ptr->rightchild)
				addq(ptr->rightchild);
		}
		else break;
	}
}