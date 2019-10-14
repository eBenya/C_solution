/*”пражнение  5.7. Ќапишите  новую  версию 
readlines, котора€ запоминала бы строки в массиве, 
определенном в main, а не запрашивала пам€ть
посредством программы alloc. Ќасколько быстрее эта 
программа?*/

#define MAXLEN 1000 /* максимальна€ длина строки */

/* readlines: чтение строк */
int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines I ! (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0'; /* убираем символ \n */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}
