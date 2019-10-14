#include <stdio.h>
#include <ctype.h>
#include <cstdlib>

#define SIZE 20  /* ????. ?????? ?????? ????? */

int main(void)
{
    int i, type, array[SIZE], getint(int *);

    for (i = 0; i < SIZE && (type = getint(&array[i])) != EOF; i++)
        printf("array[%d] = %d %s\n", i, type ? array[i] : type,
               type ? "" : "is not a number");
    system("pause");
    return 0;
}

int getch (void);
void ungetch (int);

/* getint: ?????? ????????? ????? ?? ????? ? *pn */
/* getint: ?????? ????????? ????? ?? ????? ? *pn */
int getint(int *pn){
    int c, sign;
    while ( (c = getch()) == ' '); /* ??????? ????????-???????????? */
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' ) {
       //ungetch (c); /* ?? ????? */
       return 0;
    }
    sign = (c == '-' ) ? -1 : 1;
    if (c == '+' || c == '-')
       c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0' ) ;
    *pn *= sign;
    if (c != EOF) ungetch(c);
    return c;
    }

char buf[SIZE];       /* ????? ??? ungetch */
int bufp = 0;         /* ????. ????????? ??????? ? ?????? */

int getch(void)       /* ????? (???????? ????????????) ?????? */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)   /* ??????? ?????? ?? ???? */
{
    if (bufp >= SIZE)
        printf("ungetch: ??????? ????? ????????\n");
    else
        buf[bufp++] = c;
}
