#include <stdio.h>

#define BUFSIZE 100

static char buf [BUFSIZE];  //ограничиваем область видимости переменных в пределах данного файла
static int bufp = 0;

int getch(void) /* взять (возможно возвращенный) символ */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* вернуть символ на ввод */
{
    if (bufp >= BUFSIZE)
        printf ("ungetch: слишком много символов\n");
    else
        buf[bufp++] = c;
}
