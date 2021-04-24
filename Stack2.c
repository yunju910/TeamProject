// ���� �Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
//���� �Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// ��ȣ �˻� �Լ�
int check_matching(const char* in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init_stack(&s);

	for (i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(':
			push(&s, ch);
			break;
		case ')':
			if (is_empty(&s)) return 0;
			else {
				open_ch = pop(&s);
				if (open_ch == '(' && ch != ')') {
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0;
	return 1;
}

int main(void) {
	int num = 0;
	scanf_s("%d", &num); // �ݺ��� Ƚ�� �ޱ�
	char* p = malloc(sizeof(char) * 50);  // ���� �޸� Ȱ��
	for (int i = 0; i < num; i++) {
		scanf_s("%s", p); // ���� �ޱ�
		if (check_matching(p) == 1) { // p ��ȣ Ȯ���ϱ� ��ȯ���� 1�̶�� yes
			printf("YES\n");
		}

		else {
			printf("NO\n"); //�ƴ϶�� no
		}
	}
	free(p);  // �޸� ��ȯ
	return 0;
}