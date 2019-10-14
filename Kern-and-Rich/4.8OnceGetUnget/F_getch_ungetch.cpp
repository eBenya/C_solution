/*���������� 4.8. �����������, 
��� ����� ��������, ������������ 
�����, �� ��������� 1. �������������
� ������ ����� ����� ������� getch � 
ungetch.*/

#include <stdio.h>

int getch(void);             // ����� ������ 
void ungetch (int t);        // ������� ������ �� ���� 

int buf; //���������� ������

int main() {

	int c;

	while ((c = getchar()) != EOF) {

		if (c == 'a') {//������ � �� � ��� �������� 
			ungetch('A');
			putchar(getch());

		} else putchar(c);
	}
}


int getch(void) {

	int t;

	if (buf != 0) {
		t = buf;
		buf = 0;
	}
	else t = getchar();
	return t;
}

void ungetch(int t) {

	if (buf == 0)
		buf = t;
	else printf("error: buffer overfull\n");
}
