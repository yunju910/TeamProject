1��
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 1000000 // ������ �ִ� ũ��
#define _CRT_SECURE_NO_WARNINGS

typedef int element; //�������� �ڷ���
element stack[MAX_STACK_SIZE]; // 1���� �迭�� ������ ����
int top = -1;

//�����Լ�
void push(element item) {
	stack[++top] = item;
}

//�����Լ�
void pop() {
	stack[top--] = 0;
}

int main(void) {

	int num = 0;
	int num1 = 0;
	int Sum = 0;
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf_s("%d", &num1); // �ݺ��ϰ� ���� Ƚ�� �ޱ�
		if (num1 == 0) { // 0�� ��� oop�Լ��� �̿��Ͽ� ������
			pop();
		}
		else {
			push(num1); //0�� �ƴ� �ٸ� ������ ��� ���ÿ� ����
		}
	}
	for (int i = 0; i < top + 1; i++) {
		Sum += stack[i]; // �ݺ��� ���� ��� �� ���ÿ� �ִ� �� ��� Sum�� ��ġ��
	}
	printf("%d", Sum); // �հ� ���
}

