/*���������� 4.11. ������������� 
������� getop ���, ����� ������ 
������������� � ������� ungetch.
���������: ����������� ���������� 
����������� ����������.*/

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include <locale.h>

#define MAXOP 100

/* ����������� � �������� �������� ������� */
main ()
{
    setlocale(LC_ALL, "rus"); 
    int type;
    double op2;
    char s[MAXOP];
    
    while ((type = getop (s)) != EOF) {
        switch (type) {
            case NUMBER:
                push (atof (s));
                break;
            case '+':
                push (pop() + pop());
                break;
            case '*':
                push (pop() * pop());
                break;
            case '-':
                op2 = pop();
                push (pop() - op2);
                break;
            case '/' :
                op2 = pop();
                if (op2 != 0.0)
                push (pop() / op2);
                else
                printf("������: ������� �� ����\�");
                break;
            case '\n' :
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("������: ����������� �������� %s\n", s);
                break;
        }
    }
    return 0;
}
