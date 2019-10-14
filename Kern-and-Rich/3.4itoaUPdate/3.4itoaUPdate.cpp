/*Упражнение 3.4. При условии, что для представления чисел
 используется дополнительный код, наша версия
itoa не справляется с самым большим по модулю отрицательным числом,
 значение которого равняется -(2n-1), где n — размер слова. 
 Объясните, чем это вызвано. Модифицируйте программу таким образом, 
 чтобы она давала правильное значение указанного числа
 независимо от машины, на которой выполняется.*/
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
	if ((sign = n) < 0) /* сохраняем знак */
		n = -n; /* делаем n положительным */
	i = 0;
	do { /* генерируем цифры в обратном порядке */
		s[i++] = abs(n % 10) + '0'; /* следующая цифра */
	} while ((n /= 10) != 0); /* исключить ее */
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