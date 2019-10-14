/*���������� 5.7. �������� ����� ������ 
readlines, ������� ���������� �� ������ 
� �������, ������������ � main, � �� 
����������� ������ ����������� ��������� 
alloc. ��������� ������� ��� ���������?*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* ������������ ����� ����� */
#define ALLOCSIZE 10000 /* ������ ���������� ������������ */

char *lineptr[MAXLINES]; /* ��������� �� ������ */

int readlines(char *lineptr[], int nlines, char *linebuf);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* ���������� ����� */
main(){
       
    char  buffLine[ALLOCSIZE];  
    
    int nlines; /* ���������� ����������� ����� */
    
    if ((nlines = readlines(lineptr, MAXLINES, buffLine)) >= 0) {
                
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        system("pause");
        return 0;
    } else {
        printf("������: ������� ����� �����\n");
        system("pause");
        return 1;
        }
}

#define MAXLEN 1000 /* ������������ ����� ������ */

int getline(char *, int);
char *alloc(int);

/* readlines: ������ ����� */
int readlines(char *lineptr[], int maxlines, char *linebuf){
        
    int len, nlines;
    char *p, line[MAXLEN];
    
    nlines = 0;
    
    while ((len = getline(line, MAXLEN)) > 0)
          if (nlines >= maxlines || ( len + strlen(linebuf) ) >= ALLOCSIZE-5)
             return -1;
          else {
                line[len-1] = '\0'; /* ������� ������ \n */
                strcpy(p, line);
                lineptr[nlines++] = p;
          }
    return nlines;
}  
  
/* writelines: ������ ����� */
void writelines(char *lineptr[], int nlines){
     
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* qsort: ��������� v[left]...v[right] �� ����������� */
    void qsort(char *v[], int left, int right)
    {
        int i, last;
        void swap(char *v[], int i, int j);
        if (left >= right) /* ������ �� ��������, ���� � ������� */
           return; /* ����� ���� ��������� */
        swap(v, left, (left+ right)/2);
        last = left;
        for (i = left+1; i <= right; i++)
            if (strcmp(v[i], v[left]) < 0)
               swap(v, ++last, i);
        swap(v, left, last);
        qsort(v, left, last-1);
        qsort(v, last+1, right);
    }
    
    /* swap: �������� ������� v[i] � v[j] */
    void swap(char *v[], int i, int j){
        char *temp;
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    
/* getline: ������ ������ � s, ���������� ����� */
int getline(char s[], int lim){
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == 'n') {
       s[i] = c;
       ++i;
    }
    s[i] = '\0';
    return i;
}

