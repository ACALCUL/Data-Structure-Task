#include <stdio.h>
#include <stdlib.h>
;

void stackfull();
void stacktight();
void push(int item);
int pop();

int* stack;
int capacity = 1;
int top = -1;

//queue�� �׸��� 1���̹Ƿ� element�� ������ �迭�� �̿��� �����
//cirular queue�� front, rear���� 0���� 
int* queue[5];
int rear = -1;
int front = -1;

void addq(int item);
void deleteq();

int main() {
	stack = (int*)malloc(sizeof(*stack));


	printf("��ǻ���к� 2022116778 �̵���\n");
	FILE* in;

	char i;
	int j;
	int item;
	fopen_s(&in, "in.txt", "r");
	while (fscanf_s(in, "%c", &i) != EOF) {
		if (i == 'a') {
			fscanf_s(in, "%d", &j);
			push(j);
		}
		else if (i == 'd') {
			if (top > -1)
				pop();	
		}
	}

	printf("���� 1: ");
	
	for (int k = 0; k < top+1; k++) {
		printf("%d ", stack[k]);
	}
	puts("");
	free(stack);

	//����2 ����
	rewind(in);
	while (!feof(in)) {

		fscanf_s(in, "%c", &i);
		if (i == 'a') {
			//rear==5�� ��� queuefull ����� ���� queue���� ����ϵ��� main �Լ� ����

			if ((rear+1)%5 == front) {
				printf("���� 2: ");
				printf("queuefull ");
				
				for (int k = front+1; k < rear + 1;k++) {
					printf("%d ", queue[k]);
				}

				fclose(in);

				return 0;
			}
			else{
				fscanf_s(in, "%d", &j);
				addq(j);
			}
		}
		else if (i == 'd') {
			if (front == rear);
			else
				deleteq();
		}

	}

	printf("���� 2: ");

	for (int k = front+1; k < rear + 1;k++) {
		printf("%d ", queue[k]);
	}

	fclose(in);
	
	return 0;
}


void stackfull() {
	stack = (int*)realloc(stack, 2 * capacity * sizeof(*stack));
	capacity *= 2;
}
void stacktight() {
	stack = (int*)realloc(stack, capacity * sizeof(*stack) / 2);
	capacity /= 2;
}
void push(int item) {
	stack[++top] = item;
	if (top >= capacity - 1) {
		stackfull();
	}
}

int pop() {
	if (top + 1 <= capacity / 2) {
		stacktight();
	}
	//top ==-1�϶����� pop��ü�� �����ؾ� �ϵ��� main�Լ� ����
	return stack[top--];
}

void addq(int item) {
	rear = (rear + 1) % 5;
	//rear==5�� ��� queuefull ����� ���� queue���� ����ϵ���
	//front == rear�� ��쿡�� queuefull ����� queue���� ����ϵ��� main �Լ� ����
	queue[rear] = item;
}

void deleteq() {
	//front == rear�� ��� �׳� �����ϵ��� main�Լ� ����
	front = (front + 1) % 5;
	return queue[front];
}