/*���������� 5.4. �������� ������� 
strend(s, t), ������� ������ 1, 
���� ������ t ����������� � �����
������ s, � ���� � ��������� ������.*/

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
