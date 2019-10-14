#ifndef STRING.H
        #include <string.h>
#endif
//strncpy: �������� n �������� �� t � s
void strncpy(char *t, char *s, int n) {
	
	int i = 0;

	while (i++ < n && (*s++ = *t++))
		;
}

//strncat: �������� n �������� �� t � ����� s 
void strncat(char *t, char *s, int n) {

	int i = strlen(s);
	printf("\n%d\n", i);
	s += i - 1;
	i = LEN - i - 1;
	printf("\n%d\n", i);

	if (i > n) {

		while (*++s != '\0')
			;
		for (i = 0; i < n; i++) {

			*s++ = *t++;
		}
		*s = '\0';
	}
	else
	{
		printf("not enought space for simbol");
	}
}

//strncmp: ������ < 0 ��� s < t, 0 ��� s == t, > 0 ��� s > t
int strncmp(char *t, char *s, int n) {

	for (int i = 0; (i < n) && (*s == *t); s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
		
}
