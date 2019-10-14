/*Упражнение 4.8. Предположим, 
что число символов, возвращаемых 
назад, не превышает 1. Модифицируйте
с учетом этого факта функции getch и 
ungetch.*/

#include <stdio.h>

int getch(void);             // взять символ 
void ungetch (int t);        // вернуть символ на ввод 

int buf; //переменная буфера

int main() {

	int c;

	while ((c = getchar()) != EOF) {

		if (c == 'a') {//меняем а на А для проверки 
			ungetch('A');
			putchar(getch());

		} else putchar(c);
	}
}


int getch(void) {

	int t;

	if (buf != 0) {
		t = buf;
		buf = 0;
	}
	else t = getchar();
	return t;
}

void ungetch(int t) {

	if (buf == 0)
		buf = t;
	else printf("error: buffer overfull\n");
}
