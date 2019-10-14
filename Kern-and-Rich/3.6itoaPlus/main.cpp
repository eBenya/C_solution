/*”пражнение 3.6. Ќапишите версию itoa 
с дополнительным третьим аргументом, 
задающим минимальную ширину пол€. 
ѕри необходимости преобразованное 
число должно слева дополн€тьс€ пробелами.*/

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <limits.h>

#define MAXLEN 100

void itoaPlus(int n, char s[MAXLEN], int w);
void revers(char s[MAXLEN]);

int main() {

	int dec = -123, minW = 9;
	char s[MAXLEN] = { '\0' };

	itoaPlus(dec, s, minW);

	printf("convert number %d on the base %d = %s\n", dec, minW, s);
	
	system("pause");

	return 0;
}

void itoaPlus(int n, char s[MAXLEN], int w) {

	int i = 0;
	int sign = n;

	do {
		s[i++] = abs(n % 10) + '0';

	} while ((n /= 10) != 0);

	if (sign < 0) s[i++] = '-';

	if ((i - 1) < w) while (i < w) s[i++] = ' ';
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
