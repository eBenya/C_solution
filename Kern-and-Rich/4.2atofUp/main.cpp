/*Упражнение 4.2. Дополните функцию 
atof таким образом, чтобы она 
справлялась с числами вида
123.456e-6*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define  MAXLEN 1000

int strindex(char s[MAXLEN], char[MAXLEN]);
int getline(char str[MAXLEN]);
void itoaPlus(int n, char s[MAXLEN], int w);
void revers(char s[MAXLEN]);
double atof(char s[MAXLEN]);

int main() {

	char str[MAXLEN], index[] = { "ire\0" };
	int len;
	int ii;
	double dd;

	while ((len = getline(str)) > 0) {
		
		dd = atof(str);
		printf("atof = %f\n", dd);
	}

}


int strindex(char s[MAXLEN], char t[MAXLEN]) {

	int i = 0, j = 0;

	while (s[i] != '\0') {

		//if (s[i] == t[j])
			for (j = 0; s[i] == t[j]; i++, j++);
		if (t[j] == '\0') return (i - strlen(t));
		i++;
		j = 0;

	}
	return -1;
}

int getline(char str[MAXLEN]) {
	
	char c;
	int i = 0;

	while ((c = getchar()) != '\n' && c != EOF) str[i++] = c;

	if (c == '\n') str[i++] = c;
	str[i] = '\0';
	return i;
}

void itoaPlus(int n, char s[MAXLEN], int w) {

	int i = 0;
	int sign = n;

	do {
		s[i++] = abs(n % 10) + '0';

	} while ((n /= 10) != 0);

	if (sign < 0) s[i++] = '-';

	if ((i - 1) < w) while (i < w) s[i++] = '|';
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

/* atof: преобразование строки s в double */
double atof(char s[]){

	double val, power = 1.0, a;
	int i, sign;

	for (i = 0; isspace(s[i]); i++); /* игнорирование левых символов-разделителей */

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')	i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.') {
	
		i++;
		for (power = 1.0; isdigit(s[i]); i++) {
			val = 10.0 * val + (s[i] - '0');
			power *= 10.0;
		}
	}
	
	s[0] = '\0';
	
	if (s[i] == 'e') {
		i++;
		if (s[i] == '-') {
			s[0] = s[i];
			i++;
		}

		for ( ; isdigit(s[i]); i++) a = 10 * a + (s[i] - '0');
	}
	
	if (s[0] == '-') a = -a;
	
	printf("a = %f\n", a);
	
	power = power * pow(10,-a);
	 
	return sign * val / power;
}
    
