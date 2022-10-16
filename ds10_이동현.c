#include <stdio.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;
int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;

void push(int item);
int pop();
precedence get_token(char* symbol, int* n);
void P2();

char stack2[MAX_STACK_SIZE];
char expr2[MAX_EXPR_SIZE];
int top2 = 0;

static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };

precedence get_token2(char* symbol, int* n);
void push2(char item);
int pop2();
void P1();

int main() {
	printf("컴퓨터학부 2022116778 이동현\n");
	P1();
	P2();
	return 0;
}

void push(int item) {
	stack[++top] = item;
}
int pop() {
	return stack[top--];
}

precedence get_token(char* symbol, int* n) {
	*symbol = expr[(*n)++];
	switch (*symbol) {
	case '(':
		return lparen; break;
	case ')':
		return rparen; break;
	case '+':
		return plus; break;
	case '-':
		return minus; break;
	case '/':
		return divide; break;
	case '*':
		return times; break;
	case '%':
		return mod; break;
	case '\0':
		return eos; break;
	default:
		return operand;
	}
}

void P2() {
	FILE* in2;
	fopen_s(&in2, "in2.txt", "r");
	char i;
	int j = 0;
	while (fscanf_s(in2, "%c", &i) != EOF) {
		expr[j++] = i;
	}
	fclose(in2);
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	token = get_token(&symbol, &n);
	while (token != eos) {
		if (token == operand)
			push(symbol - '0');
		else {
			op2 = pop();
			op1 = pop();
			switch (token) {
			case plus:
				push(op1 + op2); break;
			case minus:
				push(op1 - op2); break;
			case times:
				push(op1 * op2); break;
			case divide:
				push(op1 / op2); break;
			case mod:
				push(op1 % op2);
			}
		}
		token = get_token(&symbol, &n);
	}
	printf("\n문제 2: %d", pop());
}

precedence get_token2(char* symbol, int* n) {
	*symbol = expr2[(*n)++];
	switch (*symbol) {
	case '(':
		return lparen; break;
	case ')':
		return rparen; break;
	case '+':
		return plus; break;
	case '-':
		return minus; break;
	case '/':
		return divide; break;
	case '*':
		return times; break;
	case '%':
		return mod; break;
	case '\0':
		return eos; break;
	default:
		return operand;
	}
}
void push2(char item) {
	stack2[++top2] = item;
}
int pop2() {
	return stack2[top2--];
}

void print_token(precedence token)
{
	static int index = 0;
	char Char;

	switch (token) {
	case plus: Char = '+'; break;
	case minus: Char = '-'; break;
	case divide: Char = '/'; break;
	case times: Char = '*'; break;
	case mod: Char = '%'; break;
	case eos: Char = '\0'; break;
	default: Char = token;
	}
	printf("%c", Char);
}

void P1() {
	printf("문제 1: ");
	FILE* in1;
	fopen_s(&in1, "in1.txt", "r");
	char i;
	int j = 0;
	while (fscanf_s(in1, "%c", &i) != EOF) {
		expr2[j++] = i;
	}
	fclose(in1);
	char symbol;
	precedence token;
	int n = 0;

	stack2[0] = eos;
	for (token = get_token2(&symbol, &n); token != eos;
		token = get_token2(&symbol, &n)) {
		if (token == operand) {
			printf("%c", symbol);
		}
		else if (token == rparen)
		{
			while (stack2[top2] != lparen) {
				print_token(pop2());
			}
			pop2();
		}
		else {
			while (isp[stack2[top2]] >= icp[token]) {
				print_token(pop2());
			}
			push2(token);
		}
	}
	while ((token = pop2()) != eos)
		print_token(token);
}
