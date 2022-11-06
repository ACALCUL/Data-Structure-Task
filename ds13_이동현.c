#include <stdio.h>
#include <stdlib.h>

typedef struct Node* treepointer;
typedef struct Node {
	int data;
	treepointer leftc, rightc;
}Node;

void inorder(treepointer ptr);
treepointer createnode(int n);

int main() {
	printf("컴퓨터학부 2022116778 이동현\n");
	int n;
	printf("n: ");
	scanf_s("%d", &n);
	treepointer m;
	m = (treepointer)malloc(sizeof(Node));
	m = createnode(n);
	inorder(m);

	return 0;
}

void inorder(treepointer ptr) {
	if (ptr) {
		inorder(ptr->leftc);
		printf("%d ", ptr->data);
		inorder(ptr->rightc);
	}
}

treepointer createnode(int n) {
	treepointer ptr;
	ptr = (treepointer)malloc(sizeof(Node));
	ptr->data = n;
	ptr->leftc = NULL;
	ptr->rightc = NULL;
	
	if (n <=5) {
		ptr->leftc = createnode(n * 2);
	
		ptr->rightc = createnode(n + 2);
	
	}


	return ptr;
}