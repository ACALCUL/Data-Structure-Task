#include <stdio.h>

int** makeArray(int rows, int cols);

int main() {
	printf("컴퓨터학부 2022116778 이동현\n");

	FILE* in, * key;

	fopen_s(&in, "in.txt", "r");
	fopen_s(&key, "key.txt", "r");

	int** arry_in;
	int rows, cols, m;
	fscanf_s(in, "%d", &m);
	rows = m;
	fscanf_s(in, "%d", &m);
	cols = m;
	arry_in = makeArray(rows, cols);

	for (int n = 0; n < rows; n++) {

		for (int p = 0; p < cols; p++) {
			fscanf_s(in, "%d", &m);
			arry_in[n][p] = m;
			//printf("%d ", m);
		}
		//puts("");
	}

	int* arry_key;
	int n, i;
	fscanf_s(key, "%d", &i);
	n = i;
	//printf("%d ", n);
	arry_key = (int*)malloc(sizeof(int) * n);
	for (int j = 0; j < n; j++) {
		fscanf_s(key, "%d", &i);
		arry_key[j] = i;
		//printf("%d ", i);
	}
	int a;
	for (int a_1 = 0; a_1 < rows; a_1++) {
		for (int a_2 = 0; a_2 < cols - n; a_2++) {
			a = 0;
			for (int a_3 = 0; a_3 < n; a_3++) {
				if (arry_key[a_3] == arry_in[a_1][a_2 + a_3]) {
					a++;
				}
			}
			if (a == n) {
				printf("(%d, %d)", a_1, a_2);
			}
				
		}
	}




	free(arry_in);
	free(arry_key);
	fclose(in);
	fclose(key);

	return 0;
}

int** makeArray(int rows, int cols) {
	int **x;
	
	x = (int**)malloc(rows * sizeof(*x));
	//x = (int**)malloc(rows * sizeof(int*));도 가능
	for (int i = 0; i < rows; i++) {
		x[i] = (int*)malloc(cols * sizeof(**x));
		//x[i] = (int*)malloc(cols * sizeof(x));도 가능
	}
	return x;
}