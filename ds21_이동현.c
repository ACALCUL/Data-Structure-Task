#include <stdio.h>
#include <stdlib.h>


typedef struct element{
	int col[3];
} element;

void print_a(element* a, int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", a[i].col[j]);
		}
		printf("\n");
	}
}

void merge(element initlist[], element mergedlist[], int i, int m, int n, int key) {
	int j, k, t;
	j = m + 1;
	k = i;

while (i < m && j < n) {
		if (initlist[i].col[key] <= initlist[j].col[key])
			mergedlist[k++] = initlist[i++];
		else
			mergedlist[k++] = initlist[j++];
	}
	if (i > m)
		for (t = j; t <= n; t++)
			mergedlist[t] = initlist[t];
	else
		for (t = i; t <= m; t++)
			mergedlist[k + t - i] = initlist[t];
}
void mergepass(element initlist[], element mergedlist[], int n, int s, int key) {
	int i, j;
	for (i = 1; i <= n - 2 * s + 1;i += 2 * s)
		merge(initlist, mergedlist, i, i + s - 1, i + 2 * s - 1, key);
	if (i + s - 1 < n)
		merge(initlist, mergedlist, i, i + s - 1, n, key);
	else
		for (j = i; j <= n; j++)
			mergedlist[j] = initlist[j];//
}
void mergesort(element a[], int n, int key) {
	int s = 1;
	element extra[10000];

	while (s < n) {
		mergepass(a, extra, n, s, key);
		s *= 2;
		mergepass(extra, a, n, s, key);
		s *= 2;
	}
}

//int rmergesort(element a[], int link[], int left, int right) {
//	if (left >= right) return left;
//	int mid = (left + right) / 2;
//	return listmerge(a, link, rmergesort(a, link, left, mid), rmergesort(a, link, mid + 1, right));
//}
//int listmerge(element a[], int link[], int start1, int start2) {
//	int last1, last2, lastresult = 0;
//	for(last1=start1, last2=start2; last1&&last2;)
//		if (a[last1] <= a[last2]) {
//			link[lastresult] = last1;
//			lastresult = last1;last1 = link[last1];
//		}
//		else {
//			link[lastresult] = last2;
//			lastresult = last2; last2 = link[last2];
//		}
//	if (last1 == 0) link[lastresult] = last2;
//	else link[lastresult] = last1;
//	return link[0];
//}


int main() {
	printf("컴퓨터학부 2022116778 이동현\n");
	FILE* in1, * in2;
	fopen_s(&in1, "in1.txt", "r");
	fopen_s(&in2, "in2.txt", "r");
	int i, j, k, key, n, n_1, n_2;
	fscanf_s(in1, "%d", &i);
	fscanf_s(in2, "%d", &j);
	n_1 = i;
	n_2 = j;
	n = n_1+n_2;

	element *a, *b;
	a = (element*)malloc(sizeof(element) * (n + 1));
	b = (element*)malloc(sizeof(element) * (n + 1));

	//a[0]를 제외한 배열에 값 넣어주기
	for (i = 1; i <= n_1; i++) {
		for (j = 0; j < 3; j++) {
			fscanf_s(in1, "%d", &k);
			a[i].col[j] = k;
		}
	}
	for (i = n_1+1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			fscanf_s(in2, "%d", &k);
			a[i].col[j] = k;
		}
	}
	fclose(in1);
	fclose(in2);

	//b에 a정보 옮기기(a초기화용)
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			b[i].col[j] = a[i].col[j];
		}
	}

	//in1+in2 값 print
	print_a(b, n);


	printf("scanf: ");
	char c;
	scanf_s("%c", &c);
	if (c == 'X') {
		key = 0; //키 값을 0으로 설정
	}
	else if (c == 'Y') {
		key = 1; 
	}
	else if (c == 'Z') {
		key = 2; 
	}
	else
		return 0;

	mergesort(a, n, key);
	print_a(a, n);



	return 0;
}