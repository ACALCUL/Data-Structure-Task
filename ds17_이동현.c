#include <stdio.h>
#include <stdlib.h>

int* parent;

void printparent(int n);
void weightedunion(int i, int j);
int collapsingfind(int i);

int main() {
	printf("컴퓨터학부 2022116778 이동현\n");
	int n;//최대 인덱스 값(배열 크기는 이거보다 1크게)
	int i, j;//fscanf할 정수
	char c;//fscanf할 문자
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	fscanf_s(in, "%d", &i);
	n = i;
	parent = (int*)malloc(sizeof(int) * (n+1));
	for (i = 0; i <= n; i++) {
		parent[i] = -1;
	}
	while(fscanf_s(in, "%c", &c)!=EOF){
		if (c == 'U') {
			//값 두개 입력받은 후 union
			fscanf_s(in, "%d", &i);
			fscanf_s(in, "%d", &j);
			printf("U %d %d: ", i, j);
			weightedunion(i,j);
			printparent(n);
		}
		else if (c == 'F') {
			//값 하나 입력받은 후 collapsingfind
			fscanf_s(in, "%d", &i);
			printf("F %d: ", i);
			j=collapsingfind(i);
			printparent(n);
			printf("%d\n", j);
		}
		else;
	}
	return 0;
}
void printparent(int n) {
	for (int i = 0; i <= n; i++) {
		printf("%d ", parent[i]);
	}
	printf("\n");
}
void weightedunion(int i, int j) {
	int temp = parent[i] + parent[j];
	if (parent[i] >= parent[j]) {
		parent[i] = j;
		parent[j] = temp;
	}
	else {
		parent[j] = i;
		parent[i] = temp;
	}
}

int collapsingfind(int i) {
	int root, trail, lead;
	for (root = i; parent[root] >= 0; root = parent[root]);
	for (trail = i; trail != root; trail = lead) {
		lead = parent[trail];
		parent[trail] = root;
	}
	return root;
}