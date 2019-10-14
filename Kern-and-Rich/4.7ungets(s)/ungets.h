void ungets(char s[]) {

	int i = strlen(s);

	while (i > 0) ungetch(s[--i]);
}
