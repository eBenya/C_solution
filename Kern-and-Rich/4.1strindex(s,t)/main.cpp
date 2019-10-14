/*Упражнение 4.1. Напишите функцию 
strindex(s, t), которая выдает позицию 
самого правого вхождения t в s или -1, 
если вхождения не обнаружено.*/

#include <stdio.h>
#include <string.h>

#define  MAXLEN 1000

int strindex(char s[MAXLEN], char[MAXLEN]);
int getline(char str[MAXLEN]);

int main() {

	char str[MAXLEN], index[] = { "ire\0" };
	int len;
	int ii;

	while ((len = getline(str)) > 0) {
		
		ii = strindex(str, index);
		printf("start index variabl array = %d\n", ii);
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
