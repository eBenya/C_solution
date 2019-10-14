/*Упражнение 3.3. Напишите функцию
expand(s1, s2), заменяющую сокращенную
запись наподобие a-z в строке s1
эквивалентной полной записью abc. . . xyz
в s2. В s1 допускаются буквы
(прописные и строчные) и
цифры. Следует уметь справляться с
такими случаями, как a-b-c, a-z0-9 и -а-b.
Считайте знак - в начале или в
конце s1 обычным символом минус.*/


#include <cstdio>
#include "stdafx.h"

#define MAXLEN 1000

void expand(char s1[], char s2[]);


int main() {

	char str1[MAXLEN]{'\0'};
	char str2[MAXLEN]{'\0'};
	char c;
	int i = 0;

	printf("write cut string\n");

	while ( (c = getchar()) != '\n') {

		str1[i] = c;
		i++;
	}
	str1[i] = '\n';

	expand(str1, str2);

	printf("string1:\n%s\nstring2:\n%s\n", str1, str2);

}

void expand(char s1[MAXLEN], char s2[MAXLEN]) {

	int len = 0;
	int l = 0;

	while (s1[len] != '\n') len++;

	//if (s1[1] == '-') l--;
	//if (s1[len-1] == '-') len--;

	for (int i = l; i < len; i++) {

		if ( ((s1[i - 1] >= 'a') && (s1[i - 1] <= 'z')) &&
			  (s1[i] == '-') &&
			 ((s1[i + 1] >= 'a') && (s1[i + 1] <= 'z')) ) {

			for (int a = (s1[i - 1] + 1); a != s1[i + 1]; a++) {

				s2[l++] = a;
			}
			s2[l++] = s1[i+1];
			i++;

		} else if (((s1[i - 1] >= 'A') && (s1[i - 1] <= 'Z')) &&
			(s1[i] == '-') &&
			((s1[i + 1] >= 'A') && (s1[i + 1] <= 'Z'))) {

			for (int a = (s1[i - 1] + 1); a != s1[i + 1]; a++) {

				s2[l++] = a;
			}
			s2[l++] = s1[i + 1];
			i++;

		} else if (((s1[i - 1] >= '0') && (s1[i - 1] <= '9')) &&
			(s1[i] == '-') &&
			((s1[i + 1] >= '0') && (s1[i + 1] <= '9'))) {

			for (int a = (s1[i - 1] + 1); a != s1[i + 1]; a++) {

				s2[l++] = a;
			}
			s2[l++] = s1[i + 1];
			i++;

		} else{
			s2[l] = s1[i];
			l++;
		}




			
		}
	}