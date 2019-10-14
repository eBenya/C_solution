#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: получает следующий оператор или операнд */
int getop(char s[]){

	static int i = -1, c;

	if (i == -1) c = getch();

	while ((s[0] = c) == ' ' || c == '\t')
		c = getch();
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; /* ?? ????? */
	i = 0;
	if (isdigit(c)) /* ??????????? ????? ????? */
		while (isdigit(s[i++] = c))
			c = getch();
	if (c == '.') /* ??????????? ??????? ????? */
		while (isdigit(s[i++] = c))
			c = getch();
	s[i] = '\0';

	i = -1;
	return NUMBER;
}
