/*Упражнение 4-9.
Определите макрос SWAP(X, Y), который обменивает 
значениями два своих аргумента типа INT. (В 
этом случае поможет блочная структура).*/
#include <stdio.h>
#include <cstdlib>

#define SWAP(X, Y) c=X; X=Y; Y=c
int main(){
    int x, y, c;
    x = 5;
         y = 7;
    printf("x = %d; y = %d\n", x, y);
    SWAP(x,y);
    printf("x = %d; y = %d\n", x, y);
    system("pause");
         
}