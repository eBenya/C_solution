#include <cstdlib>
#include <iostream>
#include <stdio.h>

/*���������� 5.3. ��������� ���������, 
�������� ������� strcat, ������� �� 
������������� � ����� 2 (������� strcat(s, t)
�������� ������ t � ����� ������ s).*/

#define LEN 100

void StrCat(char *s, char *t);

int main() {

	char s[LEN] = "One string", t[] = "Second string";
	char *a = &s[0], *b = &t[0];

	StrCat(s, t);

	printf("\n%s\n", s);
	
	system("pause");
	return 0;
}


void StrCat(char *s, char *t) {

	while (*++s != '\0') // ??????? ????? s 
		;
	while ((*s++ = *t++) != '\0')  //???????? t 
		;

}
