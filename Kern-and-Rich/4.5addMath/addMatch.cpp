/*���������� 4.5. ������������� 
����������� ������������� � ��������� 
������������ ������� sin, exp
� pow. ��. ���������� <math.h> � 
���������� � (�������� 4).*/

#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <stdlib.h> //atof
#include <math.h>

#define BUFSIZE 100
#define MAXVAL 100 /* максимальная глубина стека */
#define MAXOP 100 /* макс. размер операнда или оператора */
#define NUMBER '0' /* признак числа */
#define  MAXLEN 1000
#define EXP 2.7182818284590451


int getch(void);
void ungetch(int);
int getop(char[]);
void push(double);
double pop(void);
/*double pfse(void);
void duplStack(void);
void change12(void);
void clrStack();*/

int main() {

	setlocale(LC_ALL, "rus");

	int type;
	double op2, op1;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '%':
				op1 = pop();
				if (op1 != 0) {
					op2 = pop();
					push(op2 - ((int)(op2 / op1) * op1));
				}
				else printf("error: degreed an 0");
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
////////////////////////////////////////////////////////////
///////////////////////Добавили/////////////////////
////////////////////////////////////////////////////////////				
			case '^':									////
				op2 = pop();							////
				op1 = pop();							////
				push( pow(op1, op2) );					////
				break;									////	
			case 's':									////
				push( sin(pop()) );						////
				break;									////
			case 'e':									////
				push( pow(EXP, pop()) );				////
				break;									////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("ошибка: неизвестная операция %s\n", s);
				break;
		}

	}
	return 0;
}

int sp = 0; /* ????????? ????????? ??????? ? ????? */
double val[MAXVAL]; /* ???? */
					/* push: ???????? ???????? f ? ???? */
void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("??????: ???? ?????, %g ?? ??????????\n", f);
}
/* pop: ????? ? ??????? ????? ? ?????? ? ???????? ?????????? */
double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("??????: ???? ????\n");
		return 0.0;
	}
}

/*if (isdigit(c) || c == '-') { // ??????????? ????? ????? 

if (c == '-')
if (isdigit(t = getch())) {
	s[++i] = t;
	while (isdigit(s[++i] = c = getch()));
}
else
{
	ungetch(t);
	return c;
}
	}*/
/* getop: ???????? ????????? ???????? ??? ??????? */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	if ( !isdigit(c) && c != '.' && c != '-' )
		return c;  /* ?? ????? */
	i = 0;
	if (c == '-')
		if (isdigit(s[++i] = c = getch()))
			while (isdigit(s[++i] = c = getch()));
		else return c;
	if (isdigit(c)) /* ??????????? ????? ????? */
		while (isdigit(s[++i] = c = getch()));
	if (c == '.') /* ??????????? ??????? ????? */
		while (isdigit(s[++i] = c = getch()));
	s[i] = '\0';
		ungetch(c);

	return NUMBER;
}


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
