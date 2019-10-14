/*Упражнение 2.7. Напишите функцию invert(х, р, n),
возвращающую значение x с инвертированными
n битами, начиная с позиции p (остальные биты не изменяются).*/

#include <cstdlib>
#include <iostream>

unsigned int invert(unsigned int x, int p, int n);

int main(){
    
    unsigned int bin = 54321; // 1101 0100 0011 0001
    int pos = 9;
    int count = 2;
    
    printf("%d\n",invert(bin, pos, count));  // жду ответ 54705 или 0b1101 0101 1011 0001
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

unsigned int invert(unsigned int x, int p, int n){
         
         return x^(~(~0 << n) << (p-n));
         
         }
