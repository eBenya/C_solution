#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

static int sp = 0;
static double val[MAXVAL];

/* push: �������� �������� f � ���� */
void push(double f){
    
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf( "������: ���� �����, %g �� ����������\n", f);
}

/* pop: ����� � ������� ����� � ������ � �������� ���������� */
double pop(void){
    if (sp > 0)
        return val[--sp];
    else {
        printf( "������: ���� ����\n");
        return 0.0;
    }
}
