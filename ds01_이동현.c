#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	printf("��ǻ���к� 2022116778 �̵���\n");
	FILE *in, *out;
	int n;
	int* arr;
	errno_t err;

	err = fopen_s(&in, "in.txt", "r");
	/*
	printf("in.txt error: %d\n", err);
	*/
	err =fopen_s(&out, "out.txt", "w");
	/*
	printf("out.txt error: %d\n", err);
	*/
	fscanf_s(in, "%d", &n);
	printf("n: %d\n", n);

	arr = (int*)malloc(sizeof(int) * n);
	int num = n;
	int i;
	for (i = 0;i < num;i++) {
		fscanf_s(in, "%d", &n);
		arr[i] = n;
	}
	/*
	for (i = 0;i < num;i++) {
		printf("%d ", arr[i]);
	}
	*/
	
	int min = arr[0];
	
	for (int i = 0; i < num; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	printf("���� ���� ��: %d \n", min);

	int min2 = arr[0];

	for (int i = 0; i < num; i++)
	{
		if (arr[i] < min2 && arr[i] != min)
			min2 = arr[i];
	}
	printf("�ι�°�� ���� ��: %d \n", min2);
	

	int x;
	do {
		scanf_s("%d", &x);
	} while (x <= 0);

	printf("%d�� ���:", x);
	for (int i = 0; i < num; i++) {
		if (arr[i] % x == 0)
			printf(" %d", arr[i]);
	}
	fclose(in);
	fclose(out);

	return 0;
}
		