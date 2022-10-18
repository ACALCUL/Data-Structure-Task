#include <stdio.h>

typedef struct listnode* listpointer;
typedef struct listnode {
	int data;
	listpointer link;
};
listpointer first;


void P1();
void insert(listpointer* firstptr, int i);

void P2();
void insert2(listpointer* first, listpointer x, int i);

int main(){
	printf("��ǻ���к� 2022116778 �̵���\n");
	P1();
	P2();
	return 0;
}

void P1() {
	printf("���� 1:\n");
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	int i;
	first = (listpointer)malloc(sizeof(*first));
	fscanf_s(in, "%d", &i);
	first->data = i;
	printf("%d\n", first->data);
	first->link = NULL;

	while (fscanf_s(in, "%d", &i) != EOF) {
		insert(&first, i);
		for (listpointer temp = first; temp; temp = temp->link) {
			printf("%d ", temp->data);
		}
		printf("\n");
	}
	//printf("%d", first->data);
}

void insert(listpointer* firstptr, int i) {
	//first�� �� �ڿ� data�� i�� ��带 �־��ִ� �Լ�
	listpointer temp;
	temp = (listpointer)malloc(sizeof(*temp));
	temp->data = i;
	listpointer temp_last=NULL;
	for (listpointer temp2 = *firstptr; temp2; temp2 = temp2->link) {
		temp_last = temp2;
	}

	if (*firstptr) {
		temp->link = temp_last->link;
		temp_last->link = temp;
	}
	else {
		temp->link = NULL;
		*firstptr = temp;
	}
	//printf("%d", temp->data);
}

void P2() {
	printf("���� 2:\n");
	int max=first->data;
	for (listpointer temp = first; temp; temp = temp->link) {
		if (temp->data > max) {
			max = temp->data;
		}
	}
	for (listpointer temp = first; temp; temp = temp->link) {
		if (temp->data == max) {
			insert2(&first, temp, -1);
		}
	}
	for (listpointer temp = first; temp; temp = temp->link) {
		printf("%d ", temp->data);
	}
}

void insert2(listpointer* first, listpointer x, int i) {
	//first�� ù° ����� ��� x �ڿ� data�� i�� ��带 �־��ִ� �Լ�
	listpointer temp;
	temp = (listpointer)malloc(sizeof(*temp));
	temp->data = i;
	if (*first) {
		temp->link = x->link;
		x->link = temp;
	}
	else {
		temp->link = NULL;
		*first = temp;
	}
}

