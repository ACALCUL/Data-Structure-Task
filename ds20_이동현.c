#include <stdio.h>
#include <stdlib.h>

void insert(int temp, int** a, int i, int col);
void insertionsort(int** a, int n, int col);
void quicksort(int** a, int left, int right, int col);
void swap(int* a, int* b, int* temp);

int main() {
	printf("��ǻ���к� 2022116778 �̵���\n");
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	int i, j, k, col, n = 1;
	while (fscanf_s(in, "%d", &i) != EOF)
		n++;
	n /= 3;
	//n�� ���� ���� ���������� 4

	rewind(in);

	int** a;
	int** b;//b
	a = (int**)malloc(sizeof(int*) * (n + 2));
	b = (int**)malloc(sizeof(int*) * (n + 2));//b
	for (i = 0; i < n + 2; i++) {
		a[i] = (int*)malloc(sizeof(int) * 3);
		b[i] = (int*)malloc(sizeof(int) * 3);//b
		//a[0]���� ����, a[n+1]���� ����
	}
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			fscanf_s(in, "%d", &k);
			a[i][j] = k;
			b[i][j] = k;//b
		}
	}
	/*for (i = 0; i <= n + 1; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	*/
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

	printf("insertionsort:\n");
	insertionsort(a, n, col);
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\nquicksort:\n");
	quicksort(b, 1, n, col);//b
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", b[i][j]);//b
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
	//�� for��� �����ͷ� �ص� �� �� ������ �� �� �غ���
	while (a[0][col] < a[i][col]) { 
		for (int j = 0; j < 3; j++) {
			a[i + 1][j] = a[i][j]; 
		}
		i--; 
	}
	for (int j = 0; j < 3; j++) {
		a[i + 1][j] = a[0][j]; 
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
		//������ printf
	}
}
void quicksort(int** a, int left, int right, int col) {
	int pivot, i, j;
	int temp[3];
	if (left < right) {
		i = left; j = right+1;
		//a[j][col] = a[i][col];->�������� �������ֽŴ�θ� �� �Լ� ������ �κ��� quicksort���� ���� �ǵ������
		pivot = a[left][col];
		do {
			do i++; while (i<=right&&a[i][col] < pivot);
			do j--; while (j>left&&a[j][col] > pivot);
			if (i < j) swap(a[i], a[j], temp);
		} while (i < j);
		swap(a[left], a[j], temp);
		quicksort(a, left, j - 1, col);
		quicksort(a, j + 1, right, col);
	}
}

void swap(int* a, int* b, int* temp) {
	for (int k = 0; k < 3; k++) {
		temp[k] = a[k];
		a[k] = b[k];
		b[k] = temp[k];
	}
}