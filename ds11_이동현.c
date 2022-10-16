#include <stdio.h>
#include <stdlib.h>

typedef struct polynode* polypointer;
typedef struct polynode {
	int coef;
	int expon;
	struct polynode* link;
};

void attach(int coefi, int expono, polypointer* ptr);
polypointer padd(polypointer a, polypointer b);


int main() {
	printf("컴퓨터학부 2022116778 이동현\n");
	FILE* a, * b;
	int i, j;

	fopen_s(&a, "a.txt", "r");
	fscanf_s(a, "%d", &i);
	polypointer* a_arr;
	a_arr = (polypointer*)malloc(sizeof(struct polynode) * i);
	for (j = 0; j < i; j++) {
		a_arr[j] = (polypointer)malloc(sizeof(struct polynode));
	}
	for (j = 0; j < i-1; j++) {
		a_arr[j]->link = a_arr[j + 1];
	}
	a_arr[j]->link = NULL;

	j = 0;
	while (fscanf_s(a, "%d", &i) != EOF) {
		a_arr[j]->coef = i;
		fscanf_s(a, "%d", &i);
		a_arr[j]->expon = i;
		j++;
	}
	fclose(a);

	//printf("%d", a_arr[0]->expon);
	//위는 값이 제대로 들어갔는지 확인하는 용도의 print

	fopen_s(&b, "b.txt", "r");
	fscanf_s(b, "%d", &i);
	polypointer* b_arr;
	b_arr = (polypointer*)malloc(sizeof(struct polynode) * i);
	for (j = 0; j < i; j++) {
		b_arr[j] = (polypointer)malloc(sizeof(struct polynode));
	}
	for (j = 0; j < i-1; j++) {
		b_arr[j]->link = b_arr[j + 1];
	}
	b_arr[j]->link = NULL;

	j = 0;
	while (fscanf_s(b, "%d", &i) != EOF) {
		b_arr[j]->coef = i;
		fscanf_s(b, "%d", &i);
		b_arr[j]->expon = i;
		j++;
	}
	fclose(b);

	polypointer c_arr;
	c_arr=padd(a_arr[0], b_arr[0]);
	polypointer temp;
	temp = c_arr;
	//삭제
	//printf("\n");
	while (temp->link != NULL) {
		printf("%d %d ", temp->coef, temp->expon);
		temp = temp->link;
	}
	printf("%d %d ", temp->coef, temp->expon);
	

	return 0;
}

void attach(int coefi, int expono, polypointer* ptr) {
	polypointer temp;
	temp = (polypointer)malloc(sizeof(*temp));
	temp->coef = coefi;
	temp->expon = expono;
	(*ptr)->link = temp;
	*ptr = temp;
}

polypointer padd(polypointer a, polypointer b) {
	polypointer c, rear, temp;
	int sum;
	rear = (polypointer)malloc(sizeof(*rear));
	c = rear;
	while (a && b) {
		//case -1
		if (a->expon < b->expon) {
			attach(b->coef, b->expon, &rear);
			//printf("%d %d ", b->coef, b->expon);
			b = b->link;
		}
		//case 0
		else if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			/*if (sum == 0) {
				b = b->link;
				a = a->link;
				continue;
			}
			*/
			if (sum) {
				attach(sum, a->expon, &rear);
				//printf("%d %d ", sum, a->expon);
			}
			a=a->link;
			b=b->link;
		}
		//case 1
		else {
			attach(a->coef, a->expon, &rear);
			//printf("%d %d ", a->coef, a->expon);
			a = a->link;
		}
	}
	for (;a;a = a->link) {
		attach(a->coef, a->expon, &rear);
		//printf("%d %d ", a->coef, a->expon);
	}
	for (;b;b = b->link) {
		attach(b->coef, b->expon, &rear);
		//printf("%d %d ", b->coef, b->expon);
	}
	rear->link = NULL;
	temp = c; c = c->link; free(temp);
	//c가 제대로 들어갔는지 확인
	//printf("%d %d ", c->coef, c->expon);
	return c;
}