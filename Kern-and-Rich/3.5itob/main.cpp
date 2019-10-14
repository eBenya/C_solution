/*���������� 3.5.�������� ������� itob(n, s, b),
������� ��������� ����� n � ������ s, ��������������
����� �� ��������� b.� ���������, itob(n, s, 16) ��������
� s ����� ����� n � ����������������� ����.*/

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <limits.h>

#define MAXLEN 100

void itob(int n, char s[MAXLEN], int b);
void revers(char s[MAXLEN]);

int main() {

	int dec = INT_MIN, basis = 7;
	char s[MAXLEN] = { '\0' };

	itob(dec, s, basis);

	printf("convert number %d on the base %d = %s\n", dec, basis, s);
    
    system("pause");
    
	return 0;
}

void itob(int n, char s[MAXLEN], int b) {

	int i = 0;
	int sign = n;

	do {
		s[i++] = abs(n % b) + '0';

	} while ((n /= b) != 0);

	if (sign < 0) s[i++] = '-';

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
