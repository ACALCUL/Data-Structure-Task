#include <stdio.h>

int main() {
	FILE* a, *b;

	fopen_s(&a, "a.txt", "r");
	fopen_s(&b, "b.txt", "r");

	printf("컴퓨터학부 2022116778 이동현\n");


	

	int a1, i, n=0;

	fscanf_s(a, "%d", &i);
	a1 = i;

	int* arry_a;
	arry_a = (int*)malloc(sizeof(int) * a1);

	while (!feof(a)) {
		fscanf_s(a, "%d", &i);
		arry_a[n] = i;
		n++;
	}

	int b1;
	n = 0;

	fscanf_s(b, "%d", &i);
	b1 = i;

	int* arry_b;
	arry_b = (int*)malloc(sizeof(int) * b1);

	while (!feof(b)) {
		fscanf_s(b, "%d", &i);
		arry_b[n] = i;
		n++;
	}

	int num_a=0, num_b=0;

	while ( (num_a != a1-1)||(num_b != b1-1) ) {
		if (arry_a[num_a] == arry_b[num_b]) {
			printf("%d ", arry_a[num_a]);
			if (!((num_a == (a1 - 1))&&(num_b==(b1-1)))) {
				num_a++;
				num_b++;
			}
		}
		else if (arry_a[num_a] > arry_b[num_b]) {
			if ( num_b != b1 - 1 ) {
				num_b++;
			}
		}
		else{
			if ( num_a != a1 - 1 ) {
				num_a++;
			}
		}
	}
	if (arry_a[num_a] == arry_b[num_b]) {
		printf("%d", arry_a[num_a]);
	}
	printf("\nO(m+n)");
	fclose(a);
	fclose(b);


	return 0;
}