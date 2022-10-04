#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef struct {
	short int vert;
	short int horiz;
} offsets;
offsets move[8];

typedef struct {
	short int row;
	short int col;
	short int dir;
}element;
element stack[MAX_STACK_SIZE];
int top = -1;

void push(element);
element pop();

int main() {
	printf("컴퓨터학부 2022116778 이동현\n");

	move[0].vert = -1; move[0].horiz = 0;
	move[1].vert = -1; move[1].horiz = 1;
	move[2].vert = 0; move[2].horiz = 1;
	move[3].vert = 1; move[3].horiz = 1;
	move[4].vert = 1; move[4].horiz = 0;
	move[5].vert = 1; move[5].horiz = -1;
	move[6].vert = 0; move[6].horiz = -1;
	move[7].vert = -1; move[7].horiz = -1;


	int start_row, start_col;
	int exit_row, exit_col;
	scanf_s("%d %d %d %d", &start_row, &start_col, &exit_row, &exit_col);
	//문제 조건에 따라 start는 1열에, exit은 5열에 위치한다.

	FILE* in, *out;
	fopen_s(&in, "in.txt", "r");
	
	int maze[7][7];
	//5X5이지만 maze[i][j]=1인 장벽을 두르기 위해서 6X6으로 함
	int i;
	
	for (int j = 0; j < 7; j++) {
		maze[0][j] = 1;
		maze[6][j] = 1;
		maze[j][0] = 1;
		maze[j][6] = 1;
	}
	for (int j = 1; j < 6; j++) {
		for (int k = 1; k < 6; k++) {
			fscanf_s(in, "%d", &i);
			maze[j][k] = i;
		}
	}


	int mark[7][7];
	for (int j = 0; j < 7; j++) {
		for (int k = 1; k < 7; k++) {
			mark[j][k] = 0;
		}
	}
	//ppt 코드 시작
	int row, col, next_row, next_col, dir, found=0;
	element position;

	mark[1][1] = 1; top = 0;
	stack[0].row = start_row; stack[0].col = start_col; stack[0].dir = 0;

	while (top > -1 && !found) {
		position = pop();
		row = position.row;
		col = position.col;
		dir = position.dir;
		
		while (dir < 8 && !found) {
			//printf("%d\n", dir);
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;
			if (next_row == exit_row && next_col == exit_col) {
				found = 1;
				position.row = row; position.col = col;
				position.dir = dir++;
				push(position);
			}
			else if (!maze[next_row][next_col] && !mark[next_row][next_col]) {
				mark[next_row][next_col] = 1;
				position.row = row; position.col = col;
				position.dir = dir++;
				push(position);
				row = next_row; col = next_col;
				dir = 0;
			}
			else ++dir;
		}
		if (!found) {
			fopen_s(&out, "out.txt", "w");
			fprintf(out, "No path");
			fclose(in);
			fclose(out);
			return 0;
		}
		position.row = next_row;
		position.col = next_col;
		position.dir = 0;
		push(position);
	}
	

	/*for (int j = 1; j < 6; j++) {
		for (int k = 1; k < 6; k++) {
			printf("%d", maze[j][k]);
		}
		printf("\n");
	}
	printf("\n");

	printf("%d\n", top);
	*/

	int a, b;
	//int c;
	for (int j = 0; j <= top; j++) {
		a = stack[j].row;
		b = stack[j].col;
		//c = stack[j].dir;
		//printf("%d %d %d\n", a, b, c);
		maze[a][b] = 2;
	}

	fopen_s(&out, "out.txt", "w");
	
	for (int j = 1; j < 6; j++) {
		for (int k = 1; k < 6; k++) {

			if (maze[j][k] == 2) {
				fprintf(out, "x");
				//printf("x");
			}
			else {
				fprintf(out, "%d", maze[j][k]);
				//printf("%d", maze[j][k]);
			}
		}
		fprintf(out, "\n");
		printf("\n");
	}

	fclose(in);
	fclose(out);
	return 0;
}

void push(element item) {
	stack[++top] = item;
}

element pop() {
	return stack[top--];
}