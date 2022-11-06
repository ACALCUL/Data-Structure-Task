#include <stdio.h>
#define MAX_ELEMENTS 1000000
#define HEAP_FULL(n) (n==MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)
int heap[MAX_ELEMENTS];

int pop(int* n);
void push(int item, int* n);

int main() {
	printf("학부: 컴퓨터학부 학번: 2022116778 이름: 이동현\n");
	int m = 0;
	int* n=&m;
	
	FILE* in;
	int i;
	fopen_s(&in, "in.txt", "r");
	while (fscanf_s(in, "%d", &i) != EOF) {
		push(i,n);
	}
	fclose(in);

	for (int j = 1; j <= (*n); j++) {
		printf("%d ", heap[j]);
	}
	//printf("\n%d\n", *n);

	printf("\nScanf_s: ");
	int k = (*n);
	scanf_s("%d", &i);
	//scanf한 i는 delete 횟수
	for (int j = 0; j < i; j++) {
		pop(n);
	}

	for (int j = 1; j <= (*n); j++) {
		printf("%d ", heap[j]);
	}
	
	return 0;
}

int pop(int* n) {
	int parent, child;
	int item, temp;
	if (HEAP_EMPTY(*n)) {
		return 0;
	}
	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	while (child <= *n) {
			if ((child < *n) && (heap[child] < heap[child + 1]))
				child++;
			if (temp >= heap[child]) break;
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
	
	}
	heap[parent] = temp;


	return item;
}

void push(int item, int* n) {
	int i;
	if (HEAP_FULL(*n)) {
		return;
	}
	i = ++(*n);
	while ((i != 1) && (item > heap[i / 2])) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}
