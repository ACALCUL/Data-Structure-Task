#include <stdio.h>
#define MAX_TERMS 101
#define MAX_COL 101
#define MAX_ROW 101

typedef struct {
	int row;
	int col;
	int value;
}term;

void fastTranspose(term a[], term b[]);

int main() {
	printf("컴퓨터학부 2022116778 이동현\n");

	FILE* m, * out;
	fopen_s(&m, "m.txt", "r");
	fopen_s(&out, "out.txt", "w");

	int x, row1, col1;
	fscanf_s(m, "%d", &x);
	row1 = x;
	fscanf_s(m, "%d", &x);
	col1 = x;

	int** arr;
	arr = (int**)malloc(sizeof(int) * row1 * col1);
	for (int i = 0; i < row1; i++) {
		arr[i] = (int*)malloc(sizeof(int) * col1);
	}

	int count = 0;
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++) {
			fscanf_s(m, "%d", &x);
			arr[i][j] = x;
		}
	}
	
	term a[MAX_TERMS];

	int y = 1;
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++) {
			if (arr[i][j] == 0);
			else {
				a[y].row = i;
				a[y].col = j;
				a[y].value = arr[i][j];
				y++;
			}
		}
	}
	a[0].row = row1;
	a[0].col = col1;
	a[0].value = y-1;
	
	for (int i = 0; i < y; i++) {
		printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
	}
	printf("\n");
	
	term b[MAX_TERMS];
	fastTranspose(a, b);

	for (int i = 0; i < y; i++) {
			x = b[i].row;
			fprintf(out, "%d ", x);
			x = b[i].col;
			fprintf(out, "%d ", x);
			x = b[i].value;
			fprintf(out, "%d\n", x);\

	}
	return 0;
}

void fastTranspose(term a[], term b[]) {
	int rowterms[MAX_COL], startingpos[MAX_COL];
	int numcols = a[0].col, numterms = a[0].value;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;

	if (numterms > 0) {
		for (int i = 0; i < numcols; i++)
			rowterms[i] = 0;

		for (int i = 1;i <= numterms; i++) {
			rowterms[a[i].col] += 1;
		}

		startingpos[0] = 1;
		for (int i = 1; i < numcols; i++)
			startingpos[i] = startingpos[i - 1] + rowterms[i - 1];

		int k;
		for (int i = 1; i <= numterms; i++) {
			k = startingpos[a[i].col]++;
			b[k].row = a[i].col;
			b[k].col = a[i].row;
			b[k].value = a[i].value;
		}
	}

}