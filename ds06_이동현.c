#include <stdio.h>
#define MAX 101

typedef struct {
	int coef;
	int expon;
}polynominal;

int avail;

void attach(float coefficient, int exponent, polynominal* array);
void padd(int s_a, int f_a, int s_b, int f_b, polynominal* array);

int main() {
	printf("컴퓨터학부 2022116778 이동현\n");
	FILE* a, * b;

	fopen_s(&a, "a.txt", "r");
	fopen_s(&b, "b.txt", "r");

	polynominal* arry;
	arry = (polynominal*)calloc(sizeof(polynominal), MAX * 3);
	int i=0, j ,n=0, a_n, b_n, s_a, s_b, f_a, f_b;
	s_a = 0;
	fscanf_s(a, "%d", &j);
	a_n = j;
	while (!feof(a)) {
		fscanf_s(a, "%d", &j);
		arry[i].coef = j;
		fscanf_s(a, "%d", &j);
		arry[i].expon = j;
		i++;
		n++;
	}
	f_a = n-1;
	s_b = n;
	fscanf_s(b, "%d", &j);
	b_n = j;
	while (!feof(b)) {
		fscanf_s(b, "%d", &j);
		arry[i].coef = j;
		fscanf_s(b, "%d", &j);
		arry[i].expon = j;
		i++;
		n++;
	}
	f_b = n - 1;
	avail = n;



	padd(s_a, f_a, s_b, f_b, arry);
	int c_n = avail;
	printf("%d ", avail-n);
	for (int m = n; m < avail; m++) {
		printf("%d %d ", arry[m].coef, arry[m].expon);
	}

	fclose(a);
	fclose(b);


	return 0;
}

void attach(int coefficient, int exponent, polynominal *array) {
	array[avail].coef = coefficient;
	array[avail++].expon = exponent;
}

void padd(int s_a, int f_a, int s_b, int f_b, polynominal* array) {
	int coefficient;
	while ((s_a <= f_a) && (s_b <= f_b)) {
		if (array[s_a].expon < array[s_b].expon) {
			attach(array[s_b].coef, array[s_b].expon, array);
			s_b++;
		}
		else if (array[s_a].expon == array[s_b].expon) {
			coefficient = array[s_a].coef + array[s_b].coef;
			if (coefficient)
				attach(coefficient, array[s_a].expon, array);
			s_a++;
			s_b++;
		}
		else {
			attach(array[s_a].coef, array[s_a].expon, array);
			s_a++;
		}
	}
	/*for (;s_a <= f_a;s_a++) {
		attach(array[s_a].coef, array[s_a].expon, array);
	}
	for (;s_b <= f_b;s_b++) {
		attach(array[s_b].coef, array[s_b].expon, array);
	}
	*/
}

