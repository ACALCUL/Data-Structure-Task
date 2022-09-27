#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int ifibo(int);
int rfibo(int);

int main() {
	clock_t start, finish1, finish2;
	double elapsed;

	printf("컴퓨터학부 2022116778 이동현\n");
	int n=0;
	
	do {
		printf("(scanf_s) ");
		scanf_s("%d", &n);
		if ((n< 0)||(n>40)) {
			return 0;
		}
		else {
			start = clock();
			printf("Iterative: %d", ifibo(n));
			finish1 = clock();
			elapsed = ((double)(finish1)-(double)(start))/CLOCKS_PER_SEC;
			printf(" (%fm/s)\n", elapsed * 1000.0);

			start = clock();
			printf("Recursive: %d", rfibo(n));
			finish2 = clock();
			elapsed = ((double)(finish2)-(double)(start))/ CLOCKS_PER_SEC;
			printf(" (%fm/s)\n", elapsed * 1000.0);

		}
	} while (n >= 0);
	return 0;
}

int ifibo(int n) {
	int *arr;
	if (n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else {
		arr = (int*)malloc(sizeof(int) * n);
		arr[0] = 0;
		arr[1] = 1;
		for (int i = 2; i < n+1; i++) {
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		return arr[n];
	}
	free(arr);
}

int rfibo(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return (rfibo(n - 1) + rfibo(n - 2));
}