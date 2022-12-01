#include <stdio.h>
#include <stdlib.h>



int digit(int data, int i, int r) {
	int num, divide=1;
	for (int j = 0; j < 4-i; j++) {
		divide *= 10;
	}
	

	num = ( (data % divide) - (data%(divide/10)) )/(divide/10); //num = data % 10^i
	if (data < divide/10)
		num = 0;

	//printf("�ڸ���(i): %d, data: %d, divide: %d, num: %d\n", i, data, divide, num);//
	return num;
}
void print_a(int a[], int link[], int first) {
	for (int i = first; i; i = link[i]) {
		printf("%04d\n", a[i]);
	}
}

//a[]������ element�� ������ �ϴ°� �迭�� ������ �ϴ°��� �������� Ȯ��->�׳� �迭����� ��

int radixsort(int a[], int link[], int d, int r, int n){
	int front[1000], rear[1000];//front[r], rear[r]�� ������ �� �ִ� ť �����->ũ�⸦ 10000���� ����
	int i, bin, current, first, last;
	first = 1;
	for (i = 1; i < n; i++) link[i] = i + 1;
	link[n] = 0;
	for (i = d - 1; i >= 0; i--) {
		for (bin = 0; bin < r;bin++) front[bin] = 0;
		for (current = first; current; current = link[current]) {
			bin = digit(a[current], i, r);
			if (front[bin] == 0) front[bin] = current;
			else link[rear[bin]] = current;
			rear[bin] = current;
		}
		for (bin = 0; !front[bin]; bin++);
		first = front[bin]; last = rear[bin];

		for (bin++;bin < r;bin++)
			if (front[bin]){
				link[last] = front[bin];
				last = rear[bin];
			}
		link[last] = 0;
	}
	return first;
}

int main() {
	printf("��ǻ���к� 2022116778 �̵���\n");
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	int i, n=0, d=4, r=8, index=1;
	while (fscanf_s(in, "%d", &i) != EOF) {
		n++;
	}
	//printf("%d", n);
	rewind(in);
	int* a, link;
	a = (int*)malloc(sizeof(int) * (n + 1));
	link = (int*)malloc(sizeof(int) * (n + 1));

	while (fscanf_s(in, "%d", &i) != EOF) {
		a[index++] = i;
	}
	fclose(in);

	//for (i = 1; i < n + 1; i++) {
	//	printf("%d\n", a[i]);
	//}
	//printf("\n");

	int first;
	first = radixsort(a, link, d, r, n);
	print_a(a, link, first);

	return 0;
}