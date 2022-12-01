#include <stdio.h>
#include <stdlib.h>

void heapsort(int a[], int n);
void swap(int a, int b, int temp);
void adjust(int a[], int root, int n);

void heapsort(int a[], int n) {
	int i, j;
	int temp=0;
	int k;
	for (i = n / 2; i > 0; i--)
		adjust(a, i, n);
	//heap build 부분

	for (i = n - 1; i > 0; i--) {
		swap(&a[1], &a[i + 1], &temp);
		adjust(a, 1, i);
		/*for (k = 1; k <= n; k++) {
			printf("%d ", a[k]);
		}
		printf("\n");*/
	}
	//heap sort 부분
}

void swap(int *a, int *b, int *temp) {
	*temp = *a;
	*a = *b;
	*b = *temp;
}

void adjust(int a[], int root, int n) {
	int child, rootkey;
	int temp;
	temp = a[root];
	rootkey = a[root];
	child = 2 * root;
	while (child <= n) {
		if ((child < n) &&
			(a[child] > a[child + 1]))
			child++;
		if (rootkey < a[child])
			break;
		else {
			a[child / 2] = a[child];
			child *= 2;
		}
	}
	a[child / 2] = temp;
}

void P1() {
	printf("문제 1: ");
	FILE* in1;
	fopen_s(&in1, "in1.txt", "r");
	int a[10000], i, j=1, n=0;
	while (fscanf_s(in1, "%d", &i) != EOF) {
		n++;
	}
	rewind(in1);
	while (fscanf_s(in1, "%d", &i) != EOF) {
		a[j++] = i;
	}
	fclose(in1);

	/*for (i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	printf("\nn: %d\n", n);*/

	heapsort(a, n);
	
	for (i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//P2 시작

int bucket = 7, slot = 3;//D대신 bucket 출력

void hash_insert(int** a, int value) {
	int key = value % bucket;
	int key_r = key, col;
	do {
		col = 0;
		while (col < 3) {
			if (a[key_r][col] == -1) {
				a[key_r][col] = value;
				return;
			}
			else
				col++;
		}
		key_r++;
		if (key_r == bucket)
			key_r = 0;
	} while (key_r != key);

}
void hash_search(int** a, int value) {
	if (value < 0) {
		printf("-1\n");
		return;
	}
	int key = value % bucket;
	int key_r = key, col;
	do {
		col = 0;
		while (col < 3) {
			if (a[key_r][col] == value) {
				printf("%d\n", key_r);
				return;
			}
			else
				col++;
		}
		key_r++;
		if (key_r == bucket)
			key_r = 0;
	} while (key_r != key);
	printf("-1\n");
}

void P2(){
	printf("문제 2:\nHash table\n");
	int** a;
	a = (int**)malloc(sizeof(int) * bucket * slot);
	//bucket: 7, slot: 3
	int i, j;
	for (i = 0; i < bucket; i++) {
		a[i] = (int*)malloc(sizeof(int) * slot);
		for (j = 0; j < slot; j++) {
			a[i][j] = -1;
		}
	}//hash table 동적할당 & 0으로 설정


	FILE* in2;
	fopen_s(&in2, "in2.txt", "r");
	while (fscanf_s(in2, "%d", &i) != EOF) {
		hash_insert(a, i);
	}//하나씩 insert해주기

	for (i = 0; i < bucket; i++) {
		printf("%d: ", i);
		for (j = 0; j < slot; j++) {
			if (a[i][j] != -1)//-1이면 출력하지 않도록 처리
				printf("%d ", a[i][j]);
		}
		printf("\n");
	}//hash table 출력

	do {
		printf("scanf: ");
		scanf_s("%d", &i);
		if (i == -999)
			break;
		hash_search(a, i);
		//printf("search-> %d\n", i);

	} while (1);//search 반복문
}

int main() {
	printf("학과: 컴퓨터학부 학번: 2022116778 이름: 이동현\n");
	P1();
	P2();
	return 0;
}
