/*���������� 3.4. ��� �������, ��� ��� ������������� �����
 ������������ �������������� ���, ���� ������
itoa �� ����������� � ����� ������� �� ������ ������������� ������,
 �������� �������� ��������� -(2n-1), ��� n � ������ �����. 
 ���������, ��� ��� �������. ������������� ��������� ����� �������, 
 ����� ��� ������ ���������� �������� ���������� �����
 ���������� �� ������, �� ������� �����������.*/
#include <cstdio>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAXLEN 1000

void itoa(int n, char s[]);
void revers(char s[MAXLEN]);

int main() {

	char str1[MAXLEN]{'\0'};
	char str2[MAXLEN]{'\0'};
	char c;
	int i = -2147483647;
	printf("int = %d\n", INT_MIN);
	itoa(INT_MIN, str1);

	printf("\n%s\n", str1);

}



void itoa(int n, char s[]){
	int i, sign;
	if ((sign = n) < 0) /* ��������� ���� */
		n = -n; /* ������ n ������������� */
	i = 0;
	do { /* ���������� ����� � �������� ������� */
		s[i++] = abs(n % 10) + '0'; /* ��������� ����� */
	} while ((n /= 10) != 0); /* ��������� �� */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	revers(s);
}

void revers(char s[MAXLEN]) {

	char c;
	int i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {

		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

}