#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int n, Min, Max;
	int* arr;
	printf("컴퓨터학부 2022116778 이동현\n(scanf) ");
	scanf_s("%d %d %d", &n, &Min, &Max);
	arr = (int*)malloc(sizeof(int) * n);
	arr[0] = 0;
	printf("%d ", arr[0]);
	for (int i = 1; i < n; i++) {
		arr[i] = arr[i-1] +rand() % (Max-Min+1) + Min;
		printf("%d ", arr[i]);
	}
	puts("");

	int searchnum, seq, iter, recur;
	clock_t start, finish;
	double elapsed;
	printf("(scanf) ");
	scanf_s("%d", &searchnum);
	while (searchnum != -1) {

		start = clock();
		seq = sesearch(arr, searchnum, 0, n - 1);
		finish = clock();
		elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
		printf("sequential search result: %d (%fms)\n", seq, elapsed * 1000.0);

		start = clock();
		iter = ibinsearch(arr, searchnum, 0, n - 1);
		finish = clock();
		elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
		printf("iterative binary search result: %d (%fms)\n", iter, elapsed * 1000.0);

		start = clock();
		recur = rbinsearch(arr, searchnum, 0, n - 1);
		finish = clock();
		elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
		printf("recursive binary search result: %d (%fms)\n", recur, elapsed * 1000.0);

		printf("(scanf) ");
		scanf_s("%d", &searchnum);
	}

	return 0;
}

int sesearch(int list[], int searchnum, int left, int right) {
	for (int i = 0; i < right + 1; i++)
	{
		if (list[i] == searchnum)
			return i;
	}
	return -1;
}

int COMPARE(int a, int b){
	if (a < b)
		return -1;
	else if (a == b)
		return 0;
	else
		return 1;
}

int ibinsearch(int list[], int searchnum, int left, int right) {
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], searchnum)) {
		case -1: left = middle + 1;
			break;
		case 0: return middle;
		case 1: right = middle - 1;
		}
	}
	return -1;
}

int rbinsearch(int list[], int searchnum, int left, int right) {
	int middle;
	if (left <= right) {
		middle = (left + right) / 2;
		if(list[middle]< searchnum)
			return rbinsearch(list, searchnum, middle + 1, right);
		else if(list[middle] == searchnum)
			return middle;
		else
			return rbinsearch(list, searchnum, left, middle - 1);
	}
	return -1;
}