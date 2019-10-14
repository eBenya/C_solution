/*����������  5.7. ��������  �����  ������ 
readlines, ������� ���������� �� ������ � �������, 
������������ � main, � �� ����������� ������
����������� ��������� alloc. ��������� ������� ��� 
���������?*/

#define MAXLEN 1000 /* ������������ ����� ������ */

/* readlines: ������ ����� */
int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines I ! (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0'; /* ������� ������ \n */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}
