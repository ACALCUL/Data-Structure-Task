#include <stdio.h>
#include <stdlib.h>

typedef struct tree* treepointer;
typedef struct tree{
	treepointer left, right;
	int data;
}tree;

treepointer queue[100000];
int front = -1, rear = -1;

treepointer maketree(int k);
void addq(treepointer item);
treepointer deleteq(void);
void levelorder(treepointer ptr);

int main() {
	printf("컴퓨터학부 2022116778 이동현\nn: ");
	int n;
	scanf_s("%d", &n);
	treepointer ptr;
	ptr= maketree(n);
	levelorder(ptr);
	return 0;
}

treepointer maketree(int k) {
	treepointer temp;
	temp = (treepointer)malloc(sizeof(tree));
	temp->data = k;
	if (k <= 5) {
		temp->left = maketree(k * 2);
		temp->right = maketree(k + 2);
	}
	else {
		temp->left = NULL;
		temp->right = NULL;
	}
	return temp;
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
			printf("%d ", ptr->data);
			if (ptr->left)
				addq(ptr->left);
			if (ptr->right)
				addq(ptr->right);
		}
		else break;
	}
}