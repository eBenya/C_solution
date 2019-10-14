/*���������� 4.5. ������������� 
����������� ������������� � ��������� 
������������ ������� sin, exp
� pow. ��. ���������� <math.h> � 
���������� � (�������� 4).*/

#include <stdio.h>
#include <tchar.h>
#include <ctype.h>
#include <stdlib.h> //atof
#include <locale.h>
#include <math.h>
#include <string.h> /* strlen() */

#define MAXVAL 100 /* максимальная глубина стека */
#define MAXOP 100 /* макс. размер операнда или оператора */
#define NUMBER '0' /* признак числа */
#define  MAXLEN 1000
#define EXP 2.7182818284590451

int line_i;
char line[MAXLEN];

int getl(char s[], int lim);
void push(double);
double pop(void);
int getop(char s[]);


int main() {

	int type;
	double op2;
	char s[MAXOP];

	setlocale(LC_ALL, "rus");

	while ( getl(line, MAXLEN) != 0) {

		line_i = 0;
		while ((type = getop(s)) != '\0')
		{
			switch (type)
			{
			case NUMBER:
				push(atof(s));
				break;
				case '+':
					push(pop() + pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '-':
					op2 = pop();
					push(pop() - op2);
					break;
				case '/':
					op2 = pop();
					if (op2 != 0.0)
						push(pop() / op2);
					else
						printf("������: ������� �� ����\n");
					break;
				case '\n':
					printf("\t%.8g\n", pop());
					break;
				default:
					printf("������: ����������� �������� %s\n", s);
					break;
			}
		}
	}
	return 0;
}

int sp = 0;
double val[MAXVAL];

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("����� � ����\n");
		return 0.0;
	}
}

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("������, ����� ������ %f �� �����\n", f);
}


int getop(char s[])
{
	int i, c;

	while ( (s[0] = c = line[line_i++]) == ' ' || c == '\t');
	s[1] = '\0';
	if ( !isdigit(c) && c != '.' && c != '-' )
		return c;  /* �� ����� */
	i = 0;
	if (c == '-')
		if (isdigit(line[line_i]))
			while (isdigit(s[++i] = line[line_i++]));
		else return c;
	if (isdigit(c)) /* ����������� ����� ����� */
		while (isdigit(s[++i] = c = line[line_i++]));
	if (c == '.') /* ����������� ������� ����� */
		while (isdigit(s[++i] = line[line_i++]));
	s[i] = '\0';
	line_i--;

	return NUMBER;
}

/* getline: ������ ������ � s, ���������� ����� */
int getl(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
