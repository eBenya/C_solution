/*Упражнение 5.4. Напишите функцию 
strend(s, t), которая выдает 1, 
если строка t расположена в конце
строки s, и нуль в противном случае.*/

#include <cstdlib>
#include <iostream>
#include <stdio.h>

#define LEN 100

int strend(char *s, char *t);

int main() {

	char s[LEN] = "One string", t[] = "String second", ne[] = "string";
	int i;

    i = strend(s, ne);
	printf("\nfor s - %d\n", i);
	
	i = strend(t, ne);
	printf("\nfor t - %d\n", i);
	
	system("pause");
	return 0;
}


int strend(char *s, char *t) {

	while (*s++ != *t)  
		;
	s--;
	while ( (*t != '\0') && *t++ == *s++ )
		;

	if ((*t == '\0') && (*s == '\0')) return 1;
	else return 0;
}
