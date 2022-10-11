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

//queue는 항목이 1개이므로 element가 정수형 배열을 이용해 만들기
//cirular queue의 front, rear값은 0으로 
int* queue[5];
int rear = -1;
int front = -1;

void addq(int item);
void deleteq();

int main() {
	stack = (int*)malloc(sizeof(*stack));


	printf("컴퓨터학부 2022116778 이동현\n");
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

	printf("문제 1: ");
	
	for (int k = 0; k < top+1; k++) {
		printf("%d ", stack[k]);
	}
	puts("");
	free(stack);

	//문제2 시작
	rewind(in);
	while (!feof(in)) {

		fscanf_s(in, "%c", &i);
		if (i == 'a') {
			//rear==5일 경우 queuefull 출력후 현재 queue내용 출력하도록 main 함수 조정

			if ((rear+1)%5 == front) {
				printf("문제 2: ");
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

	printf("문제 2: ");

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
	//top ==-1일때에는 pop자체를 무시해야 하도록 main함수 조정
	return stack[top--];
}

void addq(int item) {
	rear = (rear + 1) % 5;
	//rear==5일 경우 queuefull 출력후 현재 queue내용 출력하도록
	//front == rear일 경우에도 queuefull 출력후 queue내용 출력하도록 main 함수 조정
	queue[rear] = item;
}

void deleteq() {
	//front == rear일 경우 그냥 무시하도록 main함수 조정
	front = (front + 1) % 5;
	return queue[front];
}