/*Упражнение 5.6. Отберите подходящие 
программы из предыдущих глав и 
упражнений и перепишите их, используя 
вместо индексирования указатели. 
Подойдут, в частности, программы 
getline (главы 1 и 4), atoi, itoa и их 
варианты (главы 2, 3 и 4), reverse 
(глава 3), а также strindex и getop 
(глава 4).*/

#include <cstdlib>
#include <iostream>
#include <stdio.h>

#define LEN 20

int getline(char *s, int lim);
int atoi(char *s);
void reverse(char *s);
void itoa(int n, char *s);
int strindex(char *s, char *t);

int main() {

	char s[LEN], t[LEN] = { '4', '5', '\0' };
	int i, n;

	while (i = getline(s, LEN) != 0) {

		n = atoi(s);
		printf("\natoi - %d\n", n);
		
		itoa(n, s);
		printf("\nitoa - %s\n", s);

		n = strindex(s, t);
		printf("\nstrindex - %d\n", n);
	}

	return 0;
}

// getline: читает строку в s, возвращает длину 
int getline(char *s, int lim){

	int c, i;
	i = (int)s;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		*s = c;
		s++;
	}
	if (c == '\n')
		*s = c;
	s++;
	*s = '\0';
	return (int)s - i - 1;
}

// atoi: преобразование s в целое
int atoi(char *s){

	int i, n;
	n = 0;
	for (i = 0; *s >= '0' && *s <= '9'; ++s)
		n = 10 * n + (*s - '0');
	return n;
}

// itoa: преобразование n в строку s
void itoa(int n, char *s){

	int i = 0, sign;
	if ((sign = n) < 0) // сохраняем знак 
		n = -n; // делаем n положительным 
	do { // генерируем цифры в обратном порядке 
		*s = n % 10 + '0';
		s++;// следующая цифра 
		i++;
	} while ((n /= 10) > 0); // исключить ее 
	if (sign < 0)
		*s = '-';
	s++;
	i++;
	*s = '\0';
	s = s - (char)i;
	reverse(s);
}

// reverse: переворачивает строку s (результат в s)
void reverse(char *s){

	int c, i = 0, j;
	for (j = 0; *s != '\0'; j++, s++, i++);
	s = s - (char)i;
	j -= 2;
	for (i = 0; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

// strindex: вычисляет место t в s или выдает -1, если t нет в s
int strindex(char *s, char *t){

	int i, j, k;
	for (i = 0; *(s + i) != '\0'; i++) {
		for (j = i, k = 0; *(t + k) != '\0' && *(s + j) == *(t + k); j++, k++)
			;
		if (k > 0 && *(t + k) == '\0')
			return i;
	}
	return -1;
}