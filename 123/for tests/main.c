#include <conio.h>
#include <stdio.h>
//#include <locale.h>
 
struct Point {
    int x;
    int y;
};
 
struct Apex {
    int a;
    int b;
};
 
int main() {
     //setlocale(LC_ALL, "Rus");
     printf("текст\n");
     char c = 0;
     for(c = 1; c != 0; c++) printf("%c\n", c);
     while ((c=getchar())!=EOF){
           putchar(c);
     }
     
     
    struct Point point = {10, 20};
    struct Apex apex;
 
    apex = (*(struct Apex*)(&point));
 
    printf("a = %d, b = %d", apex.a, apex.b);
 
    getch();
    return 0;
}
