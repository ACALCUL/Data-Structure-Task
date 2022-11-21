#include <stdio.h>
#include <stdlib.h>

void insert(int temp, int** a, int i, int col);
void insertionsort(int** a, int n, int col);
void quicksort(int** a, int left, int right, int col);

int main() {
	printf("��ǻ���к� 2022116778 �̵���\n");
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	int i, j, k,col, n=1;
	while (fscanf_s(in, "%d", &i) != EOF)
		n++;
	n /= 3;
	//n�� ���� ���� ���������� 4

	rewind(in);

	int** a;
	a = (int**)malloc(sizeof(int*) * (n+2));
	for (i = 0; i < n+2; i++) {
		a[i] = (int*)malloc(sizeof(int) * 3);
		//a[0]���� ����, a[n+1]���� ����
	}
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			fscanf_s(in, "%d", &k);
			a[i][j] = k;
		}
	}
	for (i = 0; i <= n+1; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("scanf: ");
	char c;
	scanf_s("%c", &c);
	if (c == 'X') {
		col = 0; //���� 0���� ����

	}
	else if (c == 'Y') {
		col = 1; //���� 1�� ����
	}
	else if (c == 'Z') {
		col = 2; //���� 2�� ����
	}
	else
		return 0;

	//insertionsort(a, n, col);
	quicksort(a, 1, n + 1, col);
	for (i = 1; i <= n ; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void insert(int temp, int** a, int i, int col) {
	for (int j = 0; j < 3; j++) {
		a[0][j] = a[temp][j]; // 2 -1 0
	}
	//������ ppt�ڷ��� 0��� temp�� ��������� temp�� a�� ���ü��� �����Ƿ� 0�� ���
	// �����ϰ� ������ temp�� a�� �����ϰ� ����
	//int b[3] = 
	//printf("%d\n", a[temp][col]);
	while (a[0][col] < a[i][col]) { //while (a[temp][col] < a[i][col]) { 2 5 // j = 2, i =1
		for (int j = 0; j < 3; j++) {
			a[i+1][j] = a[i][j]; // a[2==temp]5 3 1 = [1]5 3 1
		}
		i--; // i = 0
	}
	for (int j = 0; j < 3; j++) {
		a[i+1][j] = a[0][j]; //a[i+1][j] = a[temp][j]; //a[1] 5 3 1
		//a[2] 5 3 1
		//a[1] 5 3 1
	}
}
void insertionsort(int** a, int n, int col) {
	for (int j = 2; j <= n; j++) {
		int temp = j;
		insert(temp, a, j - 1, col);
		/*
		for (int i = 0; i <= n; i++)
			printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
		printf("\n");
		*/
	}
}
void quicksort(int** a, int left, int right, int col) {
	int pivot, i, j;
	int temp[3];
	a[right+1][col] = a[left][col];
	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left][col];
		do {
			do i++; while (a[i][col] < pivot);
			do j--; while (a[j][col] > pivot);
		} while (i < j);
		for (int j = 0; j < 3; j++) {
			temp[j]=a[left][j];
			a[left][j] = a[i][j];
			a[i][j] = temp[j];
		}
		quicksort(a, left, j - 1, col);
		quicksort(a, j + 1, right, col);
	}
}

