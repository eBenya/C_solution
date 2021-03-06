#include <cstdlib>
#include <iostream>
#define SIZE 100

/*���������� 5.2. �������� ������� 
getfloat � ������ getint ��� ����� 
� ��������� ������. ����� ��� ����� 
����� �������������� ��������, 
���������� �������� getfloat?*/

int getch(void);
void ungetch(int c);
int getfloat(double *pn);

int main() {

	setlocale(LC_ALL, "rus");

	int i = 0, type;
    double array[SIZE];

	while ( (type = getfloat(&array[i])) != EOF ){
		if (type != -50)
			printf("array[%d] = %.3f\n", i, array[i++]);
		if (i > SIZE) i = 0;
	}

	return 0;
}
/* getfloat: ?????? ????????? ????? ?? ????? ? *pn */
int getfloat(double *pn){

	int c, ten = 1, sign;

	while (isspace(c = getch())); /* ??????? ????????-???????????? */

	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {

		return -50;
	}
	sign = (c == '-') ? -1 : 1; //???????? ?????

	if (c == '+' || c == '-')
		if (!isdigit(c = getch()))  return -50;
	for (*pn = 0; isdigit(c); c = getch())
	*pn = 10 * *pn + (c - '0');

	if (c == '.'){
		
		if (!isdigit(c = getch())) return -50;
		else {
			for ( ; isdigit(c); c = getch()) {
				*pn = 10 * *pn + (c - '0');
				ten *= 10;
			}
		}
	}

	*pn = (*pn * sign) / ten;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* ????? ??? ungetch */
int bufp = 0; /* ????, ????????? ??????? ? ?????? */

int getch(void) /* ????? (???????? ????????????) ?????? */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* ??????? ?????? ?? ???? */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: ??????? ????? ????????\n");
	else
		buf[bufp++] = c;
}
