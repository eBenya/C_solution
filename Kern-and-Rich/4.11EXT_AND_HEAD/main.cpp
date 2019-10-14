/*Упражнение 4.11. Модифицируйте 
функцию getop так, чтобы отпала 
необходимость в функции ungetch.
Подсказка: используйте внутреннюю 
статическую переменную.*/

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include <locale.h>

#define MAXOP 100

/* калькулятор с обратной польской записью */
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
                printf("ошибка: деление на нуль\п");
                break;
            case '\n' :
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("ошибка: неизвестная операция %s\n", s);
                break;
        }
    }
    return 0;
}
