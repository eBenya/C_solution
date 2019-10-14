/*Упражнение 4.5. Предусмотрите 
возможность использования в программе 
библиотечных функций sin, exp
и pow. См. библиотеку <math.h> в 
приложении В (параграф 4).*/

#include <stdio.h>
#include <tchar.h>
#include <ctype.h>
#include <stdlib.h> //atof
#include <locale.h>
#include <math.h>
#include <string.h> /* strlen() */

#define MAXVAL 100 /* РјР°РєСЃРёРјР°Р»СЊРЅР°СЏ РіР»СѓР±РёРЅР° СЃС‚РµРєР° */
#define MAXOP 100 /* РјР°РєСЃ. СЂР°Р·РјРµСЂ РѕРїРµСЂР°РЅРґР° РёР»Рё РѕРїРµСЂР°С‚РѕСЂР° */
#define NUMBER '0' /* РїСЂРёР·РЅР°Рє С‡РёСЃР»Р° */
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
						printf("ошибка: деление на нуль\n");
					break;
				case '\n':
					printf("\t%.8g\n", pop());
					break;
				default:
					printf("ошибка: неизвестная операция %s\n", s);
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
		printf("пуста в стэк\n");
		return 0.0;
	}
}

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("пистэц, стека полный %f не лезит\n", f);
}


int getop(char s[])
{
	int i, c;

	while ( (s[0] = c = line[line_i++]) == ' ' || c == '\t');
	s[1] = '\0';
	if ( !isdigit(c) && c != '.' && c != '-' )
		return c;  /* не число */
	i = 0;
	if (c == '-')
		if (isdigit(line[line_i]))
			while (isdigit(s[++i] = line[line_i++]));
		else return c;
	if (isdigit(c)) /* накапливаем целую часть */
		while (isdigit(s[++i] = c = line[line_i++]));
	if (c == '.') /* накапливаем дробную часть */
		while (isdigit(s[++i] = line[line_i++]));
	s[i] = '\0';
	line_i--;

	return NUMBER;
}

/* getline: читает строку в s, возвращает длину */
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
